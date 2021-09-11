from sys import stdin

N, M = map(int, stdin.readline().split())

dogam = {}
dogam_reverse = {}

for i in range(1, N+1):
  poketmon = input()
  dogam[i] = poketmon
  dogam_reverse[poketmon] = i

for i in range(M):
  question = stdin.readline().rstrip()
  try:
    question = int(question)
    print(dogam[question])
  except:
    print(dogam_reverse[question])
