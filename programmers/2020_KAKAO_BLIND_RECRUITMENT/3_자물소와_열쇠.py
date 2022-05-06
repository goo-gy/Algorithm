def getRotated(key):
    n = len(key)
    m = len(key[0])
    rotated = [[0] * n for i in range(m)]

    for row in range(n):
        for col in range(m):
            rotated[col][row] = key[-(row + 1)][col]
    return rotated


def solution(key, lock):
    keyLen = len(key)
    lockLen = len(lock)

    l_key = []
    current = key
    for _ in range(4):
        l_key.append(current)
        current = getRotated(current)

    for key in l_key:
        for row in range(-keyLen, lockLen):
            for col in range(-keyLen, lockLen):
                isRight = True
                for rowLock in range(lockLen):
                    for colLock in range(lockLen):
                        rowKey = rowLock - row
                        colKey = colLock - col
                        if(rowKey >= 0 and colKey >= 0 and rowKey < keyLen and colKey < keyLen):
                            check = lock[rowLock][colLock] ^ key[rowKey][colKey]
                        else:
                            check = lock[rowLock][colLock]
                        if(check == 0):
                            isRight = False
                if(isRight):
                    return True
    return False


result = solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]],
                  [[1, 1, 1], [1, 1, 0], [1, 0, 1]])
print(result)
