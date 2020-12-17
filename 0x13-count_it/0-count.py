#!/usr/bin/python3
"""
module 0-count
function count_words
"""
import requests


def count_words(subreddit, word_list, after="", counter={}, i=0):
    """Recursive function that  (case-insensitive, delimited by spaces.
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
    url = "https://api.reddit.com/r/{}/hot?after={}".format(subreddit, after)
    if i == 0:
        for word in word_list:
            counter[word] = 0
    headers = {"User-Agent": "linux:1:v1.0 (by /u/rolandoquiroz)"}
    json = requests.get(url, headers=headers).json()
    try:
        key = json['data']['after']
        parent = json['data']['children']
        for my_obj in parent:
            for word in counter:
                counter[word] += my_obj['data']['title'].lower().split(
                    ' ').count(word.lower())
        if key is not None:
            count_words(subreddit,
                        word_list,
                        key,
                        counter,
                        1)
        else:
            ans = sorted(counter.items(), key=lambda i: i[1], reverse=True)
            for key, value in ans:
                if value != 0:
                    print('{}: {}'.format(key, value))
    except Exception:
        return None
