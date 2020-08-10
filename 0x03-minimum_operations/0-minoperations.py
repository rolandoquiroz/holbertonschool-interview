#!/usr/bin/python3
"""In a text file, there is a single character H.
    Your text editor can execute only two operations in this file:
    Copy All and Paste. Given a number n, write a method that
    calculates the fewest number of operations needed to result in
    exactly n H characters in the file.

    Prototype: def minOperations(n)
    Returns an integer
    If n is impossible to achieve, return 0

Example:

n = 9

H => Copy All => Paste => HH => Paste =>HHH =>
Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed
    to result in exactly n H characters in the file.

    Args:
        n (int): Number of H characters in the file.

    Returns:
        (int): Fewest number of operations needed
        to result in exactly n H characters
    """
    if type(n) is not int or n <= 1:
        return 0

    factors = 0
    count = 2

    while count <= n:
        if n % count != 0:
            count += 1
        else:
            factors += count
            n /= count
    return factors
