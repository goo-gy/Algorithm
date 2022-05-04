ll_priority = [
    ['+', '-', '*'],
    ['+', '*', '-'],
    ['-', '+', '*'],
    ['-', '*', '+'],
    ['*', '+', '-'],
    ['*', '-', '+'],
]

class ParseTree:
    def __init__(self, expression, l_priority):
        self.l_priority = l_priority
        self.value = self.parse(expression, 0)
        
    def parse(self, expression, depth):
        if(depth >= 2):
            return eval(expression)
        
        op = self.l_priority[depth]
        expList = expression.split(op)
        resultList = []
        for exp in expList:
            result = str(self.parse(exp, depth + 1))
            resultList.append(result)
        resultExp = op.join(resultList)
        return eval(resultExp)

    def getValue(self):
        return abs(self.value)

def solution(expression):
    answer = 0
    for l_priority in ll_priority:
        parseTree = ParseTree(expression, l_priority)
        result = parseTree.getValue()
        answer = max(answer, result)
    print(answer)
    return answer
    
solution("50*6-3*2")