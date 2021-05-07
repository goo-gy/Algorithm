import math

def solution():
    N, M = list(map(int, input().split()))
    result = math.comb(max(N,M), min(N,M))
    print(result)
    
T = int(input())

for i in range(T):
    solution()