import re


moves = [(-1, 0), (0, 1), (1, 0), (0, -1)]
ROW = 0
COL = 1


def checkValid(row, col):
    if(row < 0 or col < 0 or row >= 5 or col >= 5):
        return False
    else:
        return True


def BFS(startRow, startCol, place):
    rowLen = 5
    colLen = 5
    ll_visited = [[False for col in range(colLen)] for row in range(rowLen)]
    ll_visited[startRow][startCol] = True
    queue = [(startRow, startCol, 0)]
    while(len(queue) > 0):
        row, col, dist = queue.pop(0)
        for moveRow, moveCol in moves:
            nextRow, nextCol = (row + moveRow, col + moveCol)
            if(dist >= 2):
                return True
            if(checkValid(nextRow, nextCol) and (not ll_visited[nextRow][nextCol])):
                if(place[nextRow][nextCol] == 'X'):
                    continue
                if(place[nextRow][nextCol] == 'P'):
                    return False
                ll_visited[nextRow][nextCol] = True
                queue.append((nextRow, nextCol, dist + 1))
    return True


def checkOk(place):
    for row in range(len(place)):
        for col in range(len(place[row])):
            if(place[row][col] == 'P'):
                isOk = BFS(row, col, place)
                if(not isOk):
                    return 0
    return 1


def solution(places):
    answer = []
    for place in places:
        result = checkOk(place)
        answer.append(result)
    return answer


result = solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], [
                  "PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOOP"]])
print(result)
