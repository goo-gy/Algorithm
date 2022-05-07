INF = 1234567890
wallSize = 0

l_weak = []
l_member = []
completeCount = 0
l_complete = []
s_record = []
needCount = INF


def goForward(member, start):
    global completeCount
    l_visited = []
    till = l_weak[start] + member
    for current in range(start, len(l_weak)):
        if(l_complete[current] or till < l_weak[current]):
            break
        l_visited.append(current)
        l_complete[current] = True
        completeCount += 1
    if(till >= wallSize):
        till -= wallSize
        for current in range(len(l_weak)):
            if(l_complete[current] or till < l_weak[current]):
                break
            l_visited.append(current)
            l_complete[current] = True
            completeCount += 1

    s_record.append(l_visited)


def recover():
    global completeCount
    l_visited = s_record.pop()
    for visited in l_visited:
        l_complete[visited] = False
    completeCount -= len(l_visited)


def goTest(memberIndex):
    global needCount
    if(completeCount == len(l_complete)):
        needCount = min(needCount, memberIndex)
        return
    if(memberIndex >= needCount or memberIndex >= len(l_member)):
        return
    member = l_member[memberIndex]

    for start, _ in enumerate(l_weak):
        if(l_complete[start]):
            continue
        goForward(member, start)
        goTest(memberIndex + 1)
        recover()


def solution(n, weak, dist):
    global wallSize
    global l_weak
    global l_member
    global l_complete
    wallSize = n
    l_weak = weak
    l_member = dist
    l_complete = [False for _ in l_weak]

    l_member.sort(reverse=True)
    goTest(0)
    if(needCount == INF):
        return -1
    return needCount


result = solution(12, [1, 3, 4, 9, 10], [3, 5, 7])
print(result)
