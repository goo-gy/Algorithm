import re

re_NotKorean = "[^가-힣]*"
li_set_subStr = []
li_li_similarity = [[]]

def addSubstr(sentence):
    set_subStr = set()
    for i in range(len(sentence) - 1):
        set_subStr.add(sentence[i:i+2])
    li_set_subStr.append(set_subStr)

def updateSimilarity():
    for i in range(N):
        for sub in li_set_subStr[i]:
            for j in range(i+1, N):
                if(sub in li_set_subStr[j]):
                    li_li_similarity[i][j] += 1

def getMostSimilar():
    max1 = max2 = 0
    for i in range(N):
        for j in range(i+1, N):
            if(li_li_similarity[i][j] > li_li_similarity[max1][max2]):
                max1 = i
                max2 = j
    return (max1, max2)

def get_input():
    global li_li_similarity, N
    N = int(input())
    li_li_similarity = [[ 0 for j in range(N)] for i in range(N)]
    for i in range(N):
        str_input = input()
        str_korean = re.sub(re_NotKorean, "", str_input)
        addSubstr(str_korean)

def solution():
    updateSimilarity()
    pair = getMostSimilar()
    print(pair[0] + 1, pair[1] + 1)

def main():
    get_input()
    solution()

if(__name__ == "__main__"):
    main()