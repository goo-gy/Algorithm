import re

alpha = re.compile('[A-Z]*')
CONVERTER = 65536


def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()
    dict1 = {}
    count1 = 0
    count2 = 0
    for i in range(len(str1) - 1):
        key = str1[i:i+2]
        if(not re.fullmatch(alpha, key)):
            continue
        count1 += 1
        if(key in dict1):
            dict1[key] += 1
        else:
            dict1[key] = 1

    interCount = 0
    for i in range(len(str2) - 1):
        key = str2[i:i+2]
        if(not re.fullmatch(alpha, key)):
            continue
        count2 += 1
        if(key in dict1 and dict1[key] > 0):
            interCount += 1
            dict1[key] -= 1
    unionCount = count1 + count2 - interCount
    if(unionCount == 0):
        return CONVERTER
    return int((interCount * CONVERTER) / unionCount)


print(solution("FRANCE", "french+"))
