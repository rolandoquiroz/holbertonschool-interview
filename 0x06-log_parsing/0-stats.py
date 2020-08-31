#!/usr/bin/python3
"""0-stats module"""
import sys


readed_status_codes = {'200': 0, '301': 0, '400': 0, '401': 0,
                       '403': 0, '404': 0, '405': 0, '500': 0}
file_size = 0
lines = 1
try:
    for line in sys.stdin:
        information = list(line.split(" ")[-2:])
        file_size += int(information[1])
        if len(information) >= 2:
            if information[0] in readed_status_codes.keys():
                readed_status_codes[information[0]] += 1
        if (lines % 10) == 0:
            print("File size:", file_size)
            for key, value in sorted(readed_status_codes.items()):
                if value != 0:
                    print("{}: {}".format(key, value))
        lines += 1
except KeyboardInterrupt as error:
    pass
finally:
    print("File size:", file_size)
    for key, value in sorted(readed_status_codes.items()):
        if value != 0:
            print("{}: {}".format(key, value))
