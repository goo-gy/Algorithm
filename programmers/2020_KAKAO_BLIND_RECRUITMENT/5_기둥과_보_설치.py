PILLAR = 0
BOARD = 1

DELETE = 0
CREATE = 1


class Builder:
    def __init__(self, n):
        self.size = n
        self.lll_struct = [[[False, False]
                            for col in range(n + 1)] for row in range(n + 1)]

    def checkPillar(self, x, y):
        if(y == 0 or self.lll_struct[x][y - 1][PILLAR] or self.lll_struct[x][y][BOARD]):
            return True
        if(x > 0 and self.lll_struct[x - 1][y][BOARD]):
            return True
        return False

    def checkBoard(self, x, y):
        if(y <= 0 or x >= self.size):
            return False
        if(self.lll_struct[x][y - 1][PILLAR] or self.lll_struct[x + 1][y - 1][PILLAR]):
            return True
        if(x > 0 and self.lll_struct[x - 1][y][BOARD] and self.lll_struct[x + 1][y][BOARD]):
            return True
        return False

    def create(self, x, y, struct):
        if(struct == PILLAR and self.checkPillar(x, y)):
            self.lll_struct[x][y][PILLAR] = True
        elif(struct == BOARD and self.checkBoard(x, y)):
            self.lll_struct[x][y][BOARD] = True

    def remove(self, x, y, struct):
        if(struct == PILLAR and self.lll_struct[x][y][PILLAR]):
            self.lll_struct[x][y][PILLAR] = False
            if(self.lll_struct[x][y + 1][PILLAR] and not self.checkPillar(x, y + 1)):
                self.lll_struct[x][y][PILLAR] = True
            if(self.lll_struct[x][y + 1][BOARD] and not self.checkBoard(x, y + 1)):
                self.lll_struct[x][y][PILLAR] = True
            if(self.lll_struct[x - 1][y + 1][BOARD] and not self.checkBoard(x - 1, y + 1)):
                self.lll_struct[x][y][PILLAR] = True
        elif(struct == BOARD and self.lll_struct[x][y][BOARD]):
            self.lll_struct[x][y][BOARD] = False
            if(self.lll_struct[x][y][PILLAR] and not self.checkPillar(x, y)):
                self.lll_struct[x][y][BOARD] = True
            if(self.lll_struct[x + 1][y][PILLAR] and not self.checkPillar(x + 1, y)):
                self.lll_struct[x][y][BOARD] = True
            if(self.lll_struct[x - 1][y][BOARD] and not self.checkBoard(x - 1, y)):
                self.lll_struct[x][y][BOARD] = True
            if(self.lll_struct[x + 1][y][BOARD] and not self.checkBoard(x + 1, y)):
                self.lll_struct[x][y][BOARD] = True

    def getStructures(self):
        l_structure = []
        for x in range(len(self.lll_struct)):
            for y in range(len(self.lll_struct[x])):
                if(self.lll_struct[x][y][PILLAR]):
                    l_structure.append([x, y, PILLAR])
                if(self.lll_struct[x][y][BOARD]):
                    l_structure.append([x, y, BOARD])
        return l_structure


def solution(n, build_frame):
    builder = Builder(n)
    for build in build_frame:
        x, y, struct, job = build
        if(job == CREATE):
            builder.create(x, y, struct)
        elif(job == DELETE):
            builder.remove(x, y, struct)
    return builder.getStructures()


result = solution(5, [[0, 0, 0, 1], [2, 0, 0, 1], [4, 0, 0, 1], [0, 1, 1, 1], [
                  1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [2, 0, 0, 0], [1, 1, 1, 0], [2, 2, 0, 1]])
print(result)
