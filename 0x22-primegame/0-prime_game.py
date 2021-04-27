#!/usr/bin/python3
''' Prime Game '''


def isPrime(n):
    ''' Function that determines if a number is prime'''
    if (n == 1):
        return False
    elif (n == 2):
        return True
    else:
        for x in range(2, n):
            if(n % x == 0):
                return False
        return True


def generate_numbers(num):
    ''' Generates the list of numbers from 0 to num'''
    numbers = [n for n in range(1, num + 1)]
    return numbers


def get_minimum_prime_number(list_of_numbers):
    ''' Function that gets the minimum prime number of a list of numbers'''
    for number in list_of_numbers:
        if isPrime(number):
            minimum_prime_number = number
            return (minimum_prime_number)


def filtered_numbers(minimum_prime, list_of_numbers):
    ''' Remove minimum prime and multiples from list of numbers '''
    result = filter(lambda x: x % minimum_prime != 0, list_of_numbers)
    list_of_numbers_filtered = list(result)
    return list_of_numbers_filtered


def isWinner(x, nums):
    """
    Maria and Ben are playing a game. Given a set of consecutive integers
    starting from 1 up to and including n, they take turns choosing a
    prime number from the set and removing that number and its multiples
    from the set. The player that cannot make a move loses the game.

    They play x rounds of the game, where n may be different for each round
    Assuming Maria always goes first and both players play optimally,
    determine who the winner of each game is.

    Example
    -------
    x = 3, nums = [4, 5, 1]

    First round: 4
    Maria picks 2 and removes 2, 4, leaving 1, 3
    Ben picks 3 and removes 3, leaving 1
    Ben wins because there are no prime numbers left for Maria to choose

    Second round: 5
    Maria picks 2 and removes 2, 4, leaving 1, 3, 5
    Ben picks 3 and removes 3, leaving 1, 5
    Maria picks 5 and removes 5, leaving 1
    Maria wins because there are no prime numbers left for Ben to choose

    Third round: 1
    Ben wins because there are no prime numbers for Maria to choose

    Parameters
    ----------
    x : int
        the number of rounds
    nums : list
        array of n

    Note
    ----
        You can assume n and x will not be larger than 10000

    Returns
    -------
    winner : str
        name of the player that won the most rounds
        If the winner cannot be determined, return None
    """
    length = len(nums)

    if length < 1:
        return None

    if length != x:
        return None

    gamers = ['Maria', 'Ben']

    wins = []
    for num in nums:
        my_numbers = generate_numbers(num)
        w = 0
        my_minimum_prime_number = get_minimum_prime_number(my_numbers)
        while my_minimum_prime_number is not None:
            w = w + 1
            my_numbers_filtered = filtered_numbers(my_minimum_prime_number,
                                                   my_numbers)
            my_numbers = my_numbers_filtered
            my_minimum_prime_number = get_minimum_prime_number(my_numbers)
        wins.append(gamers[w % 2 - 1])

    winner = ''
    if wins.count('Maria') > wins.count('Ben'):
        winner = 'Maria'
    elif wins.count('Maria') < wins.count('Ben'):
        winner = 'Ben'
    else:
        winner = None

    return winner
