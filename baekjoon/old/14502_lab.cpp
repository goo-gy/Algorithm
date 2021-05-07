#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int read_input();
int print_output(int result);
int solution();
int N, M;
int map[10][10];
int visited[10][10];
vector<pair<int, int>> space_list;
vector<pair<int, int>> infected_list;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
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

    // initialize
    int count = 0;
    while (!node_queue.empty())
    {
        Point current = node_queue.front();
        node_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next = { current.row + moves[i].row, current.col + moves[i].col };
            if (check_range(next) && map[next.row][next.col] == 0 && visited[next.row][next.col] == 0)
            {
                node_queue.push(next);
                visited[next.row][next.col] = 1;
                count++;
            }
        }
    }
    return count;
}

int solution()
{
    int min_infect_count = 987654321;
    for (int i = 0; i < space_list.size(); i++)
    {
        for (int j = i + 1; j < space_list.size(); j++)
        {
            for (int k = j + 1; k < space_list.size(); k++)
            {
                memset(visited, 0, 100 * sizeof(int));
                visited[space_list[i].first][space_list[i].second] = 1;
                visited[space_list[j].first][space_list[j].second] = 1;
                visited[space_list[k].first][space_list[k].second] = 1;

                int infect_count = 0;
                for (int number = 0; number < infected_list.size(); number++)
                {
                    infect_count += BFS({ infected_list[number].first, infected_list[number].second });
                }
                min_infect_count = min(min_infect_count, infect_count);
            }
        }
    }

    return space_list.size() - min_infect_count - 3;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                space_list.push_back(make_pair(i, j));
            if (map[i][j] == 2)
                infected_list.push_back(make_pair(i, j));
        }
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}