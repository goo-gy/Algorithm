#-*- coding: utf-8 -*-
import re
import sys
import math

re_NotKorean = "[^ㄱ-ㅎ|ㅏ-ㅣ|가-힣]*"
li_set_subStr = []
li_li_sim = [[]]
unionLCM = 1

def addSubstr(sentence):
    set_subStr = set()
    for i in range(len(sentence) - 1):
        set_subStr.add(sentence[i:i+2])
    li_set_subStr.append(set_subStr)

def updateSimilarity():
    global unionLCM, li_li_sim
    li_li_sim = [[ (0, 1) for j in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(i + 1, N):
            interCount = len(li_set_subStr[i].intersection(li_set_subStr[j]))
            unionCount = len(li_set_subStr[i].union(li_set_subStr[j]))
            li_li_sim[i][j] = (interCount, unionCount)
            # if(unionCount != 0):
            #     unionLCM = math.lcm(unionLCM, unionCount)

def getMostSimilar():
    max1 = max2 = 0
    simMax = 0
    for i in range(N):
        for j in range(i + 1, N):
            if(li_li_sim[i][j][1] == 0):
                continue
            # sim = unionLCM * (li_li_sim[i][j][0] / li_li_sim[i][j][1])
            sim = li_li_sim[i][j][0] / li_li_sim[i][j][1]
            if(sim > simMax):
                max1 = i
                max2 = j
                simMax = sim
    return (max1, max2)

def get_input():
    global N
    with open(sys.stdin.fileno(), encoding='utf8') as std_input:
        N = int(std_input.readline())
        # input_data = std_input.read()
        # lines = input_data.split('$')
        # for line in lines[:N]:
        for i in range(N):
            line = std_input.readline()
            str_korean = re.sub(re_NotKorean, "", line)
            addSubstr(str_korean)

def solution():
    updateSimilarity()
    pair = getMostSimilar()
    print(pair[0] + 1, pair[1] + 1)

if(__name__ == "__main__"):
    get_input()
    solution()