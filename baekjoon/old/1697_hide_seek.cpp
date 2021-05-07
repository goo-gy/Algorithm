#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <

using namespace std;

#define RANGE_MAX 100000

int read_input();
int print_output(int result);
int solution();
int N, K;
int distance_map[RANGE_MAX + 1];

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int find_brother()
{
    queue<int> next_queue;
    next_queue.push(K);
    distance_map[K] = 0;

    while (!next_queue.empty())
    {
        int current = next_queue.front();
        next_queue.pop();

        int next;
        if (current % 2 == 0 && current != 0)
        {
            next = current / 2;
            if (true)
                if (distance_map[next] == -1)
                {
                    next_queue.push(next);
                    distance_map[next] = distance_map[current] + 1;
                }
        }
        if (current > 0)
        {
            next = current - 1;
            if (distance_map[next] == -1)
            {
                next_queue.push(next);
                distance_map[next] = distance_map[current] + 1;
            }
        }
        if (current < RANGE_MAX)
        {
            next = current + 1;
            if (distance_map[next] == -1)
            {
                next_queue.push(next);
                distance_map[next] = distance_map[current] + 1;
            }
        }
    }
    return distance_map[N];
}

int solution()
{
    memset(distance_map, -1, (RANGE_MAX+1) * sizeof(int));
    int result = find_brother();
    return result;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}