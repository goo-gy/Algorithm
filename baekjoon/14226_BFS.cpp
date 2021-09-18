#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

#define INF 1234567890

using namespace std;
int visited[2000][2000];
int N;

int check_valid(tuple<int, int, int> next)
{
    return (get<0>(next) < 2 * N && get<0>(next) >= 0) && (!visited[get<0>(next)][get<1>(next)]);
}

int BFS()
{
    queue<tuple<int, int, int>> node_queue;
    node_queue.push({1, 0, 0});

    while (!node_queue.empty())
    {
        tuple<int, int, int> current = node_queue.front();
        node_queue.pop();

        if(get<0>(current) == N)
            return get<2>(current);
        visited[get<0>(current)][get<1>(current)] = 1;

        tuple<int, int, int> next;

        next = {get<0>(current), get<0>(current), get<2>(current) + 1};
        if (check_valid(next))
        {
            node_queue.push(next);
            visited[get<0>(next)][get<1>(next)] = 1;
        }
        next = {get<0>(current) + get<1>(current), get<1>(current), get<2>(current) + 1};
        if (check_valid(next))
        {
            node_queue.push(next);
            visited[get<0>(next)][get<1>(next)] = 1;
        }
        next = {get<0>(current) - 1, get<1>(current), get<2>(current) + 1};
        if (check_valid(next))
        {
            node_queue.push(next);
            visited[get<0>(next)][get<1>(next)] = 1;
        }
    }
    return 0;
}

int solution()
{
    // input
    cin >> N;

    // solution
    memset(visited, 0, 2000 * 2000 * sizeof(int));
    int result = BFS();

    // output
    cout << result << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}