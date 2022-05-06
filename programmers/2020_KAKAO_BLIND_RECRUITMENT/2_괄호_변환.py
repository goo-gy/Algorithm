def isRight(u):
    countOpen = 0
    for bracket in u:
        if(bracket == '('):
            countOpen += 1
        else:
            countOpen -= 1
        if(countOpen < 0):
            return False
    if(countOpen == 0):
        return True
    else:
        return False


def convertRight(w):
    if(w == ''):
        return w

    countOpen = 0
    countClose = 0

    u = ""
    v = ""
    for index, bracket in enumerate(w):
        if(bracket == '('):
            countOpen += 1
        else:
            countClose += 1
        if(countOpen == countClose):
            index += 1
            break

    u = w[:index]
    v = w[index:]
    if(isRight(u)):
        return u + convertRight(v)
    else:
        str_result = '(' + convertRight(v) + ')'
        for bracket in u[1:-1]:
            if(bracket == '('):
                str_result += ')'
            else:
                str_result += '('
        return str_result


def solution(p):
    return convertRight(p)


result = solution("(()())()")
print(result)
