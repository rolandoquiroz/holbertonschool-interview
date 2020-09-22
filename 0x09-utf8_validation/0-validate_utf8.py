#!/usr/bin/python3
"""
0-validate_utf8 module
contains the function: validUTF8
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding

        Args:
            data: `list`, the data is represented by a list of integers

        Returns:
            True if data is a vaflid UTF-8 encoding, else return False
    """
    number_of_bytes = 0
    mask1 = 0b10000000
    mask2 = 0b01000000
    for number in data:
        mask = 0b10000000
        if number_of_bytes == 0:
            while mask & number:
                number_of_bytes += 1
                mask = mask >> 1
            if number_of_bytes == 0:
                continue
            if number_of_bytes == 1 or number_of_bytes > 4:
                return False
        else:
            if not (number & mask1 and not (number & mask2)):
                return False
        number_of_bytes -= 1
    return number_of_bytes == 0
