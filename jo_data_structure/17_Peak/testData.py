import random

N = 10000
data = []
for i in range(N):
    begin = random.randint(1, 999999)
    end = random.randint(begin + 1, 1000000)
    row = "%d %d" %(begin, end)
    data.append(row)
f = open("big.inp", 'w')
f.write('\n'.join(data))
f.close()
