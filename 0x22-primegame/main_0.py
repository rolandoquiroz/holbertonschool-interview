#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))

print("Winner: {}".format(isWinner(5, [0, 0, 0, 0, 0])))

print("Winner: {}".format(isWinner(5, [1, 1, 1, 1, 1])))

print("Winner: {}".format(isWinner(5, ['a', 0, 0, 0, 0])))