#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

int test_case();
int read_input();
int print_output(long long result);
long long solution();
int T;
int N, M, K;
vector<vector<int>> field;
vector<pair<int, int>> cabbage_list;

int main()
{
    test_case();
    return 0;
}


struct Point
{
    int row, col;
};

Point moves[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool check_range(Point p)
{
    return (p.row >= 0 && p.col >= 0 && p.row < N&& p.col < M);
}

int BFS(Point start)
{
    queue<Point> node_queue;
    node_queue.push(start);

    if (field[start.row][start.col] == 0)
        return 0;

    // initialize
    field[start.row][start.col] = 0;

    while (!node_queue.empty())
    {
        Point current = node_queue.front();
        node_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next = { current.row + moves[i].row, current.col + moves[i].col };
            if (check_range(next) && field[next.row][next.col] == 1)
            {
                field[next.row][next.col] = 0;
                node_queue.push(next);
            }
        }
    }
    return 1;
}


long long solution()
{
    int count = 0;
    for (int i = 0; i < K; i++)
    {
        count += BFS({ cabbage_list[i].first, cabbage_list[i].second });
    }


    return count;
}

int test_case()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        read_input();
        long long result = solution();
        print_output(result);
    }
    return 0;
}

int read_input()
{
    cin >> N >> M >> K;

    field.resize(N);
    for (int i = 0; i < N; i++)
    {
        field[i].resize(M);
    }

    cabbage_list.resize(K);
    for (int i = 0; i < K; i++)
    {
        cin >> cabbage_list[i].first >> cabbage_list[i].second;
        field[cabbage_list[i].first][cabbage_list[i].second] = 1;
    }

    return 0;
}

int print_output(long long result)
{
    cout << result << endl;
    return 0;
}