def solution(gems):
    set_gems = set()
    for gem in gems:
        set_gems.add(gem)
    targetCount = len(set_gems)
    dict_gemCount = { gem:0 for gem in set_gems }
    
    start = 0
    end = 0
    count = 0
    li_allGemRange = []
    while(True):
        if(start >= len(gems) or end >= len(gems)):
            break
        if(count == targetCount):
            dict_gemCount[gems[start - 1]] -= 1
            if(dict_gemCount[gems[start - 1]] == 0):
                count -= 1
        else:
            dict_gemCount[gems[end]] += 1
            if(dict_gemCount[gems[end]] == 1):
                count += 1

        if(count == targetCount):
            li_allGemRange.append([start, end])
            start += 1
        else:
            end += 1
    
    minRange = li_allGemRange[0]
    for allGemRange in li_allGemRange:
        if(allGemRange[1] - allGemRange[0] < minRange[1] - minRange[0]):
            minRange = allGemRange

    return [minRange[0] + 1, minRange[1] + 1]

result = solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"])
print(result)