def getLen(cutLen, s):
    l_word = [s[i:i+cutLen] for i in range(0, len(s), cutLen)]
    totalLen = 0
    prevWord = ""
    repeatCount = 0
    for word in l_word:
        if(word == prevWord):
            repeatCount += 1
        else:
            if(repeatCount > 0):
                totalLen += len(str(repeatCount + 1))
            totalLen += len(word)
            prevWord = word
            repeatCount = 0
    if(repeatCount > 0):
        totalLen += len(str(repeatCount))
    return totalLen


def solution(s):
    answer = len(s)
    for cutLen in range(1, len(s) + 1):
        answer = min(answer, getLen(cutLen, s))
    return answer


result = solution("aabbaccc")
print(result)
