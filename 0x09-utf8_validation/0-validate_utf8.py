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
    if data == [] or len(data) == 0:
        return False

    checked = []
    i = 0
    while (len(data)) > (len(checked)):
        if ((data[i] & 255) > 247):
            return False
        if (0 <= (data[i] & 255) <= 127):
            checked.append(1)
        if (192 <= (data[i] & 255) <= 223):
            checked.append(1)
            if (128 <= (data[i+1] & 255) <= 191):
                checked.append(1)
            else:
                return False
        if (224 <= (data[i] & 255) <= 239):
            checked.append(1)
            for j in range(1, 3):
                if (128 <= (data[i+j] & 255) <= 191):
                    checked.append(1)
                else:
                    return False
        if (240 <= (data[i] & 255) <= 247):
            checked.append(1)
            for j in range(1, 4):
                if (128 <= (data[i+j] & 255) <= 191):
                    checked.append(1)
                else:
                    return False
        i += 1
    return all(checked)
