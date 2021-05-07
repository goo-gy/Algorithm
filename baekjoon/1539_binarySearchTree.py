from bisect import bisect_left, bisect_right

VALUE = 0
DEPTH = 1
depth_sum = 0

N = int(input())
array = []
for i in range(N):
    value = int(input())
    index = bisect_left(array, (value, 0))
    depth = max(array[index-1][DEPTH] if(index > 0) else 1, array[index][DEPTH] if(index < i) else 1) + 1
    array.insert(index, (value, depth))
    depth_sum += depth

print(depth_sum)