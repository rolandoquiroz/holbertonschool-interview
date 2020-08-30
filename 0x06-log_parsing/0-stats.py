#!/usr/bin/python3
import sys
import signal


def keyboardInterruptHandler(signal, frame):
    print("File size:", file_size)
    for key, value in sorted(readed_status_codes.items()):
        if value != 0:
            print('{}: {}'.format(key, value))
    exit(0)


signal.signal(signal.SIGINT, keyboardInterruptHandler)


readed_status_codes = {200: 0, 301: 0, 400: 0, 401: 0,
                       403: 0, 404: 0, 405: 0, 500: 0}
file_size = 0
lines = 0
count_200 = 0
count_301 = 0
count_400 = 0
count_401 = 0
count_403 = 0
count_404 = 0
count_405 = 0
count_500 = 0
while (1):
    line = sys.stdin.readline()
    information = list(map(int, (line.partition('1"')[2]).split()))
    if len(information) == 2:
        file_size += information[1]
        if information[0] in readed_status_codes.keys():
            if information[0] == 200:
                count_200 += 1
                readed_status_codes[information[0]] = count_200
            if information[0] == 301:
                count_301 += 1
                readed_status_codes[information[0]] = count_301
            if information[0] == 400:
                count_400 += 1
                readed_status_codes[information[0]] = count_400
            if information[0] == 401:
                count_401 += 1
                readed_status_codes[information[0]] = count_401
            if information[0] == 403:
                count_403 += 1
                readed_status_codes[information[0]] = count_403
            if information[0] == 404:
                count_404 += 1
                readed_status_codes[information[0]] = count_404
            if information[0] == 405:
                count_405 += 1
                readed_status_codes[information[0]] = count_405
            if information[0] == 500:
                count_500 += 1
                readed_status_codes[information[0]] = count_500
    if lines != 0 and lines % 10 == 0:
        print("File size:", file_size)
        for key, value in sorted(readed_status_codes.items()):
            if value != 0:
                print('{}: {}'.format(key, value))
    lines += 1
