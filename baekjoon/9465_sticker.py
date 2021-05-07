NONE = 0
UP = 1
DOWN = 2

def solution():
    N = int(input())
    up_stickers = list(map(int, input().split()))
    down_stickers = list(map(int, input().split()))

    dp = [[0 for _ in up_stickers] for _ in range(3)]
    dp[NONE][0] = 0
    dp[UP][0] = up_stickers[0]
    dp[DOWN][0] = down_stickers[0]

    for i in range(1, N):
        dp[NONE][i] = max(dp[UP][i-1], dp[DOWN][i-1])
        dp[UP][i] = max(dp[NONE][i-1], dp[DOWN][i-1]) + up_stickers[i]
        dp[DOWN][i] = max(dp[NONE][i-1], dp[UP][i-1]) + down_stickers[i]
    print(max(dp[NONE][N-1], max(dp[UP][N-1], dp[DOWN][N-1])))

T = int(input())

for i in range(T):
    solution()
