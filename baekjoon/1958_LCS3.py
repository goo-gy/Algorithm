str1 = input()
str2 = input()
str3 = input()

DP = [ [ [ 0 for _ in range(len(str3)+1)] for _ in range(len(str2)+1)] for _ in range(len(str1)+1)]

for index1, alpha1 in enumerate(str1):
    for index2, alpha2 in enumerate(str2):
        for index3, alpha3 in enumerate(str3):
            value_plus = DP[index1 - 1][index2 - 1][index3 - 1] + (1 if (alpha1 == alpha2 == alpha3) else 0)
            DP[index1][index2][index3] = max(value_plus, 
                DP[index1][index2][index3 - 1],
                DP[index1][index2 - 1][index3],
                DP[index1][index2 - 1][index3 - 1],
                DP[index1 - 1][index2][index3],
                DP[index1 - 1][index2][index3 - 1],
                DP[index1 - 1][index2 - 1][index3])
print(DP[len(str1) - 1][len(str2) - 1][len(str3) - 1])