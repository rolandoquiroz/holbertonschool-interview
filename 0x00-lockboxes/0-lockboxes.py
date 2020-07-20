#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other
boxes.

This module contains a method called canUnlockAll that determines
if all the boxes can be opened.

- Prototype: def canUnlockAll(boxes)
- boxes is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- The first box boxes[0] is unlocked
- Return True if all boxes can be opened, else return False

This file can also be imported as a module and contains the following
function methods:

    * canUnlockAll - Determines if all the boxes can be opened
    * 0-main - the main function of the script

"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened.

    Args:
        boxes (list): A list of lists

    Returns:
        (bool): True if all boxes can be opened, else return False
    """
    needed_keys = []
    keys = []
    can_be_opened = []
    opened = []

    for i in range(len(boxes)):
        needed_keys.append(i)
        keys.append(None)
        can_be_opened.append(False)
        opened.append(False)

    keys[0] = 0
    can_be_opened[0] = True

    while (((can_be_opened) != (opened))):
        for i in range(len(boxes)):
            if ((keys[i] == i) and (can_be_opened[i] is True) and
                    (opened[i] is False)):
                for number in boxes[i]:
                    if ((number in needed_keys) and (number not in keys)):
                        keys[number] = number
                        can_be_opened[number] = True
                    else:
                        continue
                opened[i] = True
               
    if can_be_opened is True:
        return True
    return False
