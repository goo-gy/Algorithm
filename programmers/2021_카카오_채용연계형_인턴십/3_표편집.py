class IndexTree:
    def __init__(self, n):
        self.leafLeft = 1
        while(self.leafLeft < n):
            self.leafLeft *= 2

        self.itemSize = n
        self.treeSize = self.leafLeft * 2
        self.l_tree = [0 for i in range(self.treeSize)]
        for i in range(self.itemSize):
            self.update(i, 1)

    def updateCount(self, index):
        self.l_tree[index] = \
            self.l_tree[index * 2] + self.l_tree[index * 2 + 1]

        if(index > 1):
            self.updateCount(int(index / 2))

    def update(self, index, value):
        treeIndex = self.leafLeft + index
        self.l_tree[treeIndex] = value
        self.updateCount(int(treeIndex / 2))

    def getCount(self, start, end):
        count = 0
        L = self.leafLeft + start
        R = self.leafLeft + end
        while(L < R):
            nextL = int((L + 1) / 2)
            nextR = int((R - 1) / 2)
            parentL = int(L / 2)
            parentR = int(R / 2)
            if(nextL != parentL):
                count += self.l_tree[L]
            if(nextR != parentR):
                count += self.l_tree[R]
            L = nextL
            R = nextR
        if(L == R):
            count += self.l_tree[L]
        return count

    def getState(self):
        return self.l_tree[self.leafLeft: self.leafLeft + self.itemSize]


class Controller:
    def __init__(self, n, k):
        self.memberTree = IndexTree(n)
        self.position = k
        self.s_deleted = []
        self.n = n

    def parametricUp(self, count):
        end = self.position - 1
        prevStart = 0
        prevEnd = end
        while(prevStart != prevEnd):
            current = int((prevStart + prevEnd) / 2)
            if(self.memberTree.getCount(current, end) >= count):
                prevStart = current + 1
            elif(self.memberTree.getCount(current, end) < count):
                prevEnd = current
        if(self.memberTree.getCount(prevEnd, end) >= count):
            return prevEnd
        else:
            return prevEnd - 1

    def parametricDown(self, count):
        start = self.position + 1
        prevStart = start
        prevEnd = self.n - 1
        while(prevStart != prevEnd):
            current = int((prevStart + prevEnd) / 2)
            if(self.memberTree.getCount(start, current) >= count):
                prevEnd = current
            elif(self.memberTree.getCount(start, current) < count):
                prevStart = current + 1
        if(self.memberTree.getCount(start, prevStart) >= count):
            return prevStart
        else:
            return prevStart + 1

    def moveUp(self, jumpSize):
        if(len(self.s_deleted) == self.n):
            return
        self.position = self.parametricUp(jumpSize)
        if(self.position < 0):
            self.position = -1
            self.moveDown(1)

    def moveDown(self, jumpSize):
        if(len(self.s_deleted) == self.n):
            return
        self.position = self.parametricDown(jumpSize)
        if(self.position >= self.n):
            self.position = self.n
            self.moveUp(1)

    def delete(self):
        self.memberTree.update(self.position, 0)
        self.s_deleted.append(self.position)
        if(self.position == self.n - 1):
            self.position = self.n
            self.moveUp(1)
        else:
            self.moveDown(1)

    def recover(self):
        recoverIndex = self.s_deleted.pop()
        self.memberTree.update(recoverIndex, 1)
        if(len(self.s_deleted) == self.n - 1):
            self.position = recoverIndex

    def getState(self):
        l_isAlive = self.memberTree.getState()
        l_answer = []
        for isAlive in l_isAlive:
            state = 'O' if isAlive else 'X'
            l_answer.append(state)
        return ''.join(l_answer)


def solution(n, k, l_cmd):
    controller = Controller(n, k)
    for cmd in l_cmd:
        command = cmd.split(' ')
        if(command[0] == 'U'):
            jumpSize = int(command[1])
            controller.moveUp(jumpSize)
        if(command[0] == 'D'):
            jumpSize = int(command[1])
            controller.moveDown(jumpSize)
        if(command[0] == 'C'):
            controller.delete()
        if(command[0] == 'Z'):
            controller.recover()

    answer = controller.getState()
    return answer


result = solution(8, 2, ["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"])
print(result)
