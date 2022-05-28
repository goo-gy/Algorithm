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
    l_busCrew = [[] for i in range(n)]

    crew = 0
    bus = 0
    while(crew < len(l_crewMin) and bus < n):
        if(l_crewMin[crew] > l_busMin[bus] or len(l_busCrew[bus]) >= m):
            bus += 1
            continue
        l_busCrew[bus].append(l_crewMin[crew])
        crew += 1
    if(len(l_busCrew[-1]) < m):
        return min_to_time(l_busMin[-1])
    return min_to_time(l_busCrew[-1][-1] - 1)


result = solution(2, 10, 2, ["09:05", "09:09",
                  "09:13", "12:13", "12:13", "12:13"])
print(result)
