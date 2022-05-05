def isEnough(length):
    countSum = 0
    for wire in l_wire:
        count = int(wire / length)
        countSum += count
    if(countSum >= N):
        return True
    else:
        return False


def pararmetric(end):
    assert 0 < end
    prevStart = 1
    prevEnd = end
    while(prevStart != prevEnd):
        current = int((prevStart + prevEnd)/2)
        if(isEnough(current)):
            prevStart = current + 1
        else:
            prevEnd = current
    if(isEnough(prevStart)):
        return prevStart
    else:
        return prevStart - 1


l_wire = []
K, N = list(map(int, input().split()))
maxLen = 0
for i in range(K):
    length = int(input())
    l_wire.append(length)
    maxLen = max(maxLen, length)

result = pararmetric(maxLen)
print(result)
