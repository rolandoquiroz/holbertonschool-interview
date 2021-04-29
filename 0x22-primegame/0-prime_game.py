#!/usr/bin/python3
''' Prime Game '''


def isPrime(number):
    ''' Function that determines if a number is prime'''
    if (number == 1):
        return False
    elif (number == 2):
        return True
    else:
        for n in range(2, number):
            if(number % n == 0):
                return False
        return True


def get_minimum_prime_number(list_of_numbers):
    ''' Function that gets the minimum prime number of a list of numbers'''
    for number in list_of_numbers:
        if isPrime(number):
            minimum_prime_number = number
            return (minimum_prime_number)


def filter_numbers(minimum_prime_number, list_of_numbers):
    ''' Remove minimum prime number and its multiples from list of numbers '''
    result = filter(lambda x: x % minimum_prime_number != 0, list_of_numbers)
    list_of_filtered_numbers = list(result)
    return list_of_filtered_numbers


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

    Result: Ben has the most wins

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

    if not nums:
        return None

    if x < 1:
        return None

    winsMaria = 0
    winsBen = 0
    for rnd in range(x):

        if (type(nums[rnd]) is not int):
            return None

        my_numbers = [num for num in range(1, nums[rnd] + 1)]
        w = 0
        my_minimum_prime_number = get_minimum_prime_number(my_numbers)
        while my_minimum_prime_number is not None:
            w = w + 1
            my_filtered_numbers = filter_numbers(my_minimum_prime_number,
                                                 my_numbers)
            my_numbers = my_filtered_numbers
            my_minimum_prime_number = get_minimum_prime_number(my_numbers)
        if w % 2 - 1:
            winsBen += 1
        else:
            winsMaria += 1

    if winsMaria > winsBen:
        return 'Maria'
    elif winsMaria < winsBen:
        return 'Ben'

    return None
