#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define RANGE 1002

int N;
int target_x, target_y;

pair<int, int> moves[] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
int matrix[RANGE][RANGE];
int visited[RANGE][RANGE];

void initialize_board()
{
    memset(matrix, 0, RANGE * RANGE * sizeof(int));
    memset(matrix, 0, RANGE * RANGE * sizeof(int));
}

bool check_range(pair<int, int> p)
{
    return (p.first >= 0 && p.second >= 0 && p.first <= RANGE && p.second <= RANGE);
}

int BFS(pair<int, int> start)
{
    queue<pair<pair<int, int>, int>> node_queue;
    node_queue.push(make_pair(start, 0));

    // initialize
    visited[start.first][start.second] = 1;

    while (!node_queue.empty())
    {
        pair<pair<int, int>, int> current = node_queue.front();
        node_queue.pop();

        if (current.first.first == target_x && current.first.second == target_y)
            return current.second;
        for (int i = 0; i < 4; i++)
        {
            pair<pair<int, int>, int> next = make_pair(make_pair(current.first.first + moves[i].first, current.first.second + moves[i].second), current.second + 1);
            if (check_range(next.first) && !visited[next.first.first][next.first.second] && matrix[next.first.first][next.first.second] == 0)
            {
                // do something
                visited[next.first.first][next.first.second] = 1;
                node_queue.push(next);
            }
        }
    }
    return 0;
}

int solution()
{
    // input
    cin >> target_x >> target_y >> N;
    target_x += 500;
    target_y += 500;
    initialize_board();
    for (int i = 0; i < N; i++)
    {
        int pool_x, pool_y;
        cin >> pool_x >> pool_y;
        matrix[pool_x + 500][pool_y + 500] = 1;
    }

    // solution
    int distance = BFS(make_pair(500, 500));

    // output
    cout << distance << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}