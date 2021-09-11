#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define RANGE 101

int R, C;
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
    return (p.first >= 1 && p.second >= 1 && p.first <= R && p.second <= C);
}


int BFS(pair<int, int> start, int water_height)
{
    if (visited[start.first][start.second] || matrix[start.first][start.second] <= water_height)
        return 0;

    queue<pair<int, int>> node_queue;
    node_queue.push(start);

    // initialize
    visited[start.first][start.second] = 1;
    
    while(!node_queue.empty())
    {
        pair<int, int> current = node_queue.front();
        node_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {current.first + moves[i].first, current.second + moves[i].second};
            if(check_range(next) && !visited[next.first][next.second] && matrix[next.first][next.second] > water_height)
            {
                // do something
                visited[next.first][next.second] = 1;
                node_queue.push(next);
            }
        }
    }
    return 1;
}

int solution()
{
    // input
    cin >> R;
    C = R;
    int max_height = 0;
    initialize_board();
    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
        {
            cin >> matrix[r][c];
            max_height = max(max_height, matrix[r][c]);
        }
    }

    // solution
    int max_count = 0;
    for (int water_height = 0; water_height < max_height; water_height++)
    {
        int count = 0;
        memset(visited, 0, RANGE * RANGE * sizeof(int));
        for (int r = 1; r <= R; r++)
        {
            for (int c = 1; c <= C; c++)
            {
                count += BFS(make_pair(r, c), water_height);
            }
        }
        max_count = max(max_count, count);
    }

    // output
    cout << max_count;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
