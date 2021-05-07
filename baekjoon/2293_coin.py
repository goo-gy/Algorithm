buffer = 2
def solution():
    N, K = list(map(int, input().split()))
    coins = [ None ]
    DP = [ [ 0 for _ in range(K+1)] for _ in range(2)]
    for i in range(N):
        coin = int(input())
        coins.append(coin)
    
    DP[0][0] = 1
    DP[1][0] = 1

    for n in range(1, N+1):
      coin = coins[n]
      n_converted = n % buffer
      for k in range(1, K+1):
        DP[n_converted][k] = DP[n_converted-1][k]
        if(k - coin >= 0):
          DP[n_converted][k] += DP[n_converted][k - coin]
    print(DP[n_converted][K])

solution()