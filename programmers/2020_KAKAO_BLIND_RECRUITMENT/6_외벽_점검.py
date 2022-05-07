wallSize = 0
l_weak = []
l_member = []

completeCount = 0
l_complete = []
l_dist = []
l_direct = [-1, 1]
s_record = []

INF = 1234567890


def goTest(memberIndex):
    global completeCount
    if(completeCount == len(l_complete)):
        return memberIndex

    if(memberIndex >= len(l_member)):
        return INF
    member = l_member[memberIndex]

    needCount = INF
    for start, _ in enumerate(l_weak):
        if(l_complete[start]):
            continue
        for direct in l_direct:
            # go
            current = start
            time = member
            l_visited = []
            while(time >= 0):
                if(l_complete[current]):
                    break
                l_visited.append(current)
                l_complete[current] = True
                completeCount += 1
                next = (current + direct + len(l_weak)) % len(l_weak)
                if(next == start):
                    break
                high = max(l_weak[current], l_weak[next])
                low = min(l_weak[current], l_weak[next])
                if((current == 0 and next == len(l_weak) - 1) or (next == 0 and current == len(l_weak) - 1)):
                    distance = (low - high + wallSize) % wallSize
                else:
                    distance = high - low
                time -= distance
                current = next
            #
            s_record.append(l_visited)
            needCount = min(needCount, goTest(memberIndex + 1))
            # recover
            l_visited = s_record.pop()
            for visited in l_visited:
                l_complete[visited] = False
            completeCount -= len(l_visited)
    return needCount


def solution(n, weak, dist):
    global wallSize
    global l_weak
    global l_member
    global l_complete
    wallSize = n
    l_weak = weak
    l_member = dist
    l_complete = [False for _ in l_weak]

    for index, _ in enumerate(l_weak):
        distance = (l_weak[index] - l_weak[index - 1] + n) % n
        l_dist.append(distance)

    l_member.sort(reverse=True)
    answer = goTest(0)

    return answer


result = solution(12, [10, 0],  [1, 2])
print(result)
