INF = 1234567890
 
city_count = int(input())
bus_count = int(input())

bus_map = [ [ INF for _ in range(city_count + 1) ] for _ in range(city_count + 1) ]

for i in range(bus_count):
    src, dst, cost = map(int, input().split())
    if(cost < bus_map[src][dst]):
        bus_map[src][dst] = cost

# floyd
for middle in range(1, city_count+1):
    for src in range(1, city_count+1):
        for dst in range(1, city_count+1):
            if(src == dst):
                continue
            new_cost = bus_map[src][middle] + bus_map[middle][dst]
            if(new_cost < bus_map[src][dst]):
                bus_map[src][dst] = new_cost

# output
result_string = ""
for src in range(1, city_count+1):
    for dst in range(1, city_count+1):
        if(bus_map[src][dst] == INF):
            bus_map[src][dst] = 0
        result_string += str(bus_map[src][dst]) + ' '
    result_string += "\n"
print(result_string)