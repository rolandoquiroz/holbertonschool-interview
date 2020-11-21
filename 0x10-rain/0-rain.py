#!/usr/bin/python3
"""
module 0-rain
contains function rain
"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.

    Arguments:
        walls: list
            A list of non-negative integers

        Return: int
            total amount of rainwater retained
    """
    rain = 0
    n = len(walls)
    if walls and n:
        for i in range(1, n - 1):
            left = walls[i]
            for j in range(i):
                left = max(left, walls[j])
            right = walls[i]
            for j in range(i + 1, n):
                right = max(right, walls[j])
            rain += min(left, right) - walls[i]

    return rain
