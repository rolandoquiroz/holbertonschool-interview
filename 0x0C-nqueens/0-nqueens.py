#!/usr/bin/python3
"""0-nqueens
contains a program that solves the N queens problem"""
from sys import argv, exit


def solve(N, i=0, a=[], b=[], c=[]):
    """Generates backtracking solutions for N queens problem"""
    if i < N:
        for j in range(N):
            if j not in a and i+j not in b and i-j not in c:
                for solution in solve(N, i+1, a+[j], b+[i+j], c+[i-j]):
                    yield solution
    else:
        yield a


if __name__ == "__main__":

    if not len(argv) == 2:
        print("Usage: nqueens N")
        exit(1)

    if not (argv[1]).isdigit():
        print("N must be a number")
        exit(1)

    N = int(argv[1])
    if N < 4:
        print("N must be at least 4")
        exit(1)

for solution in solve(N):
    ans = [[c, r] for c, r in enumerate(solution)]
    print(ans)
