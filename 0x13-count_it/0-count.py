#!/usr/bin/python3
"""
module 0-count
function count_words
"""
import requests


def count_words(subreddit, word_list, keyword_count={}, next_page=None,
                re_keywords={}):
    """Recursive function that queries the Reddit API, parses
    the title of all hot articles, and prints a sorted count
    of given keywords (case-insensitive, delimited by spaces.
    Javascript should count as javascript, but java should not).
    Args:
        subreddit: (str)
            subreddit to search
        word_list: (list)
            words to search
        titles: (list)
            titles of the subreddit
    Returns:
        None
    """
    headers = {'User-Agent': 'linux:1:v1.0 (by /u/rolandoquiroz)'}
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)

    if next_page:
        response = requests.get(url +
                                '?after=' +
                                next_page,
                                headers=headers)
    else:
        response = requests.get(url,
                                headers=headers)

    if response.status_code == 404:
        return

    if keyword_count == {}:
        for word in word_list:
            keyword_count[word] = 0
            re_keywords[word] = word_list.count(word)

    response_dict = response.json()
    response_data = response_dict['data']
    next_page = response_data['after']
    response_posts = response_data['children']

    for post in response_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in keyword_count:
                if w.lower() == key.lower():
                    keyword_count[key] += 1

    if next_page:
        count_words(subreddit, word_list, keyword_count, next_page,
                    re_keywords)

    else:
        for key, value in re_keywords.items():
            if value > 1:
                keyword_count[key] *= value

        sorted_abc = sorted(keyword_count.items(), key=lambda x: x[0])
        sorted_ans = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for ans in sorted_ans:
            if ans[1]:
                print('{}: {}'.format(ans[0], ans[1]))
