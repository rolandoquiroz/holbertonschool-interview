#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 2]
    print(rain(walls))
    walls = [3, 0, 2, 0, 4]
    print(rain(walls))
    walls = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(rain(walls))
