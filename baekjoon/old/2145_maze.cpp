#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Point
{
    int row, col;
};

int read_input();
int print_output(int result);
int solution();
int N, M;
vector<vector<int>> maze;
vector<vector<int>> distance_map;

int move_row[4] = {-1, 0, 1, 0};
int move_col[4] = {0, 1, 0, -1};

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

bool check_range(Point point)
{
    return (point.row >= 0 && point.col >= 0 && point.row < N && point.col < M);
}

int solution()
{
    Point end_point = {N - 1, M - 1};
    queue<Point> queue;
    queue.push({0, 0});

    distance_map[0][0] = 1;
    while(!queue.empty())
    {
        Point current = queue.front();
        queue.pop();

        for(int i = 0; i < 4; i++)
        {
            Point new_point = {current.row + move_row[i], current.col + move_col[i]};
            if(check_range(new_point) && maze[new_point.row][new_point.col] == 1)
            {
                // do
                distance_map[new_point.row][new_point.col] = distance_map[current.row][current.col] + 1;
                if(new_point.row == end_point.row && new_point.col == end_point.col)
                    return distance_map[new_point.row][new_point.col];
                // make it wall
                maze[new_point.row][new_point.col] = 0;
                queue.push(new_point);
            }
        }
    }
    return 0;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    maze.resize(N);
    distance_map.resize(N);

    string str_row;
    const char *space;
    for(int i = 0; i < N; i++)
    {
        maze[i].resize(M);
        distance_map[i].resize(M, 0);
        cin >> str_row;
        space = str_row.c_str();
        for(int j = 0; j < M; j++)
        {
            maze[i][j] = *(space + j) - 0x30;
        }
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}