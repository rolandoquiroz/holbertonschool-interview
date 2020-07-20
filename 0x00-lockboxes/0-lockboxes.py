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
"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened.
    Args:
        boxes (list): A list of lists
    Returns:
        (bool): True if all boxes can be opened, else return False
    """
    needed_keys = []
    for i in range(len(boxes)):
        needed_keys.append(i)

    got_keys = []
    got_keys.append(0)

    for key in got_keys:
        for new_key in boxes[key]:
            if ((new_key in needed_keys) and (new_key not in got_keys)):
                got_keys.append(new_key)
            else:
                continue
            if needed_keys == sorted(got_keys):
                return True
    return False
