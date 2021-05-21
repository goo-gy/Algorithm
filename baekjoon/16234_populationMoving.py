import sys
import queue

MOVES = [(-1, 0), (0, 1), (1, 0), (0, -1)]

N, L, R = map(int, sys.stdin.readline().rstrip().split())

pop_map = []
for i in range(N):
    pop_row = list(map(int, sys.stdin.readline().rstrip().split()))
    pop_map.append(pop_row)

def is_valid_location(row, col, N):
    if( 0 <= row < N and 0 <= col < N):
        return True
    else:
        return False

def BFS(pop_map, visited, start_row, start_col, group_number):
    next_queue = queue.Queue()
    next_queue.put((start_row, start_col))
    pop_sum = 0
    count = 0
    while(not next_queue.empty()):
        row, col = next_queue.get()
        pop_sum += pop_map[row][col]
        count += 1
        visited[row][col] = group_number
        
        for MOVE in MOVES:
            next_row = row + MOVE[0]
            next_col = col + MOVE[1]
            if(is_valid_location(next_row, next_col, len(pop_map)) and ( L <= abs(pop_map[row][col] - pop_map[next_row][next_col]) <= R) ):
                if(not visited[next_row][next_col]):
                    next_queue.put((next_row, next_col))
                    visited[next_row][next_col] = group_number
    return (pop_sum, count)

move_count = 0
while(True):
    visited = [ [ False for _ in range(N) ] for _ in range(N) ]
    group_number = 1
    groups = [None]
    have_group = False
    for row in range(N):
        for col in range(N):
            if(not visited[row][col]):
                pop_sum, city_count = BFS(pop_map, visited, row, col, group_number)
                if(city_count > 1):
                    have_group = True
                groups.append(int(pop_sum / city_count))
                group_number += 1
    if(have_group):
        move_count += 1
    else:
        break
    for row in range(N):
        for col in range(N):
            group_number = visited[row][col]
            if(group_number):
                pop_map[row][col] = groups[group_number]

print(move_count)