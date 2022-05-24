from datetime import datetime

times = []


def parseTime(str_time):
    h, m, S = str_time.split(':')
    s, ms = S.split('.')
    time = (int(h) * 3600 + int(m) * 60 + int(s)) * 1000 + int(ms)
    return time


def parseLength(time):
    time = time[:-1]
    if('.' in time):
        pad = 5 - len(time)
        time += ('0' * pad)
        s, ms = list(map(int, time.split('.')))
    else:
        s = int(time)
        ms = 0
    return s * 1000 + ms


def solution(lines):
    for line in lines:
        str_date, str_time, str_length = line.split(' ')
        end_time = parseTime(str_time)
        length = parseLength(str_length)
        start_time = end_time - length + 1
        times.append([start_time, end_time])

    maxCount = 0
    for index, current in enumerate(times):
        count = 0
        start, end = current
        checkStart = end + 1000 - 1
        for next in times[index:]:
            nextStart, nextEnd = next
            if(nextStart <= checkStart):
                count += 1
        maxCount = max(maxCount, count)
    return maxCount


result = solution(["2016-09-15 01:00:04.001 2.0s",
                  "2016-09-15 01:00:07.000 2s"])

print(result)
