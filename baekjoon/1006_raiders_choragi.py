INF = 9876543210

AA = 0
AH = 1
HA = 2
HH = 3
V  = 4

def find_min(DP, K):
    min_value = DP[K][0]
    for i in range(5):
        if(DP[K][i] < min_value):
            min_value = DP[K][i]
    return min_value

def count_middle(inner_area, outer_area, N, W, option):
    DP = [ [ 2, INF, INF, INF, INF ] for _ in range(N) ]
    
    if(option == 0):
        DP[0] = [ 2, INF, INF, INF, INF ]
        if(inner_area[0] + outer_area[0] <= W):
            DP[0][V] = 1
    elif(option == 1):
        DP[0] = [ INF, 1, INF, INF, INF ]
    elif(option == 2):
        DP[0] = [ INF, INF, 1, INF, INF ]
    elif(option == 3):
        DP[0] = [ INF, INF, INF, 0, INF ]

    TILL = N - 1
    if(option == 0):
        TILL = N
    for i in range(1, TILL):
        outer_H = outer_area[i] + outer_area[i-1] <= W
        inner_H = inner_area[i] + inner_area[i-1] <= W

        DP[i][AA] = find_min(DP, i-1) + 2
        DP[i][AH] = min((DP[i-1][AA] + 1), (DP[i-1][HA] + 1)) if ( outer_H ) else INF
        DP[i][HA] = min((DP[i-1][AA] + 1), (DP[i-1][AH] + 1)) if ( inner_H ) else INF
        DP[i][HH] = DP[i-1][AA] if (outer_H and inner_H) else INF
        DP[i][V] = (DP[i][AA] - 1) if ( inner_area[i] + outer_area[i] <= W ) else INF

    LAST = N - 1
    outer_H = outer_area[LAST] + outer_area[LAST - 1] <= W
    inner_H = inner_area[LAST] + inner_area[LAST-  1] <= W
    if(option == 1): 
        DP[LAST][AA] = find_min(DP, LAST-1) + 2
        DP[LAST][HA] = min((DP[LAST - 1][AA] + 1), (DP[LAST - 1][AH] + 1)) if ( inner_H ) else INF
    elif(option == 2):
        DP[LAST][AA] = find_min(DP, LAST-1) + 2
        DP[LAST][AH] = min((DP[LAST - 1][AA] + 1), (DP[LAST - 1][HA] + 1)) if ( outer_H ) else INF
    elif(option == 3):
        DP[LAST][AA] = find_min(DP, LAST-1) + 2

    return find_min(DP, N-1)

def solution():
    N, W = list(map(int, input().split()))
    inner_area = list(map(int, input().split()))
    outer_area = list(map(int, input().split()))

    take_outer = outer_area[0] + outer_area[-1] <= W
    take_inner = inner_area[0] + inner_area[-1] <= W
    count = count_middle(inner_area, outer_area, N, W, 0)
    if(N > 1):
        if(take_outer):
            count = min(count, count_middle(inner_area, outer_area, N, W, 1))
        if(take_inner):
            count = min(count, count_middle(inner_area, outer_area, N, W, 2))
        if(take_outer and take_inner):
            count = min(count, count_middle(inner_area, outer_area, N, W, 3))
    print(count)
    
T = int(input())
for i in range(T):
    solution()