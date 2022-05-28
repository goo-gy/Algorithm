START_MIN = 540


def min_to_time(timeMin):
    return "%02d:%02d" % (int(timeMin / 60), timeMin % 60)


def time_to_min(str_time):
    h, m = map(int, str_time.split(":"))
    return 60 * h + m


def solution(n, t, m, timetable):
    l_busMin = []
    for i in range(n):
        busMin = START_MIN + t * i
        l_busMin.append(busMin)

    l_crewMin = [time_to_min(crew) for crew in timetable]
    l_crewMin.sort()
    l_busCrew = [0 for i in range(n)]

    crew = 0
    bus = 0
    while(crew < len(l_crewMin) and bus < n):
        if(l_crewMin[crew] <= l_busMin[bus]):
            l_busCrew[bus] += 1
            crew += 1
        else:
            bus += 1
    l_crewMin = l_crewMin[:crew]

    for index in range(0, n - 1):
        overflow = l_busCrew[index] - m
        if(overflow > 0):
            l_busCrew[index] -= overflow
            l_busCrew[index + 1] += overflow

    overflow = l_busCrew[-1] - m
    if(overflow < 0):
        return min_to_time(l_busMin[-1])
    if(overflow > 0):
        l_crewMin = l_crewMin[:-overflow]

    return min_to_time(l_crewMin[-1] - 1)


result = solution(2, 10, 2, ["09:05", "09:09",
                  "09:13", "12:13", "12:13", "12:13"])
print(result)
