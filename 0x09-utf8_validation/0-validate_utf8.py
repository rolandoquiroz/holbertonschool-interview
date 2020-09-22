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
            True if data is a valid UTF-8 encoding, else return False
    """
    bytes_number = 0
    mask1 = 0b10000000
    mask2 = 0b01000000
    for num in data:
        mask = 0b10000000
        if bytes_number == 0:
            while mask & num:
                bytes_number += 1
                mask = mask >> 1
            if bytes_number == 0:
                continue
            if bytes_number == 1 or bytes_number > 4:
                return False
        else:
            if not (num & mask1 and not (num & mask2)):
                return False
        bytes_number -= 1
    return bytes_number == 0
