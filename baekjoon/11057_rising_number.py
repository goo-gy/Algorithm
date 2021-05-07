N = int(input())
DP = [ [ 0 for i in range(10)] for _ in range(N) ]

for i in range(10):
    DP[-1][i] = 10 - i

def all_case(depth, start):
    if(DP[depth][start] > 0):
        return DP[depth][start]

    count_part = 0
    for number in range(start, 10):
        count_part += all_case(depth + 1, number)
    DP[depth][start] = count_part
    return DP[depth][start]        

count = all_case(0, 0)
print(count)