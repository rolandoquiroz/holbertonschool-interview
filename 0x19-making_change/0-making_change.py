#!/usr/bin/python3
"""function makeChange"""

def makeChange(coins, total):
    """             
    Function that given a pile of coins of different values, determine
    the fewest number of coins needed to meet a given amount total.

    Parameters
    ----------
    coins : list
        the values of the coins in your possession
        The value of a coin will always be an integer greater than 0
        You can assume you have an infinite number of each denomination
        of coin in the list
    total : int
        given amount total to meet
        If total is 0 or less, return 0
        If total cannot be met by any number of coins, return -1

    Returns
    -------
    change : int
        fewest number of coins needed to meet total
    """
    Opt = [0 for i in range(0, total + 1)]

    n = len(coins)
    for i in range(1, total + 1):
        smallest = float("inf")
        for j in range(0, n):
            if (coins[j] <= i):
                smallest = min(smallest, Opt[i - coins[j]])
        Opt[i] = 1 + smallest

    if type(Opt[total]) is float:
        return -1
    return Opt[total]
