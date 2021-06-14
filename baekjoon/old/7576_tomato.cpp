#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Point
{
    int row, col;
};

Point moves[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int read_input();
int print_output(int result);
int solution();
int N, M;
vector<vector<int>> tomato_box;
queue<Point> main_queue;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

bool check_range(Point p)
{
    return (p.row >= 0 && p.col >= 0 && p.row < M&& p.col < N);
}

int distributed_BFS()
{
    bool all_empty = false;
    int days_go = -1;
    queue<Point> backup_queue;
    while (!main_queue.empty())
    {
        days_go++;
        // distributed
        all_empty = true;
        while (!main_queue.empty())
        {
            Point current = main_queue.front();
            main_queue.pop();
            // moves
            for (int i = 0; i < 4; i++)
            {
                Point next = { current.row + moves[i].row, current.col + moves[i].col };
                if (check_range(next) && tomato_box[next.row][next.col] == 0)
                {
                    backup_queue.push(next);
                    tomato_box[next.row][next.col] = 1;
                }
            }
        }
        while (!backup_queue.empty())
        {
            main_queue.push(backup_queue.front());
            backup_queue.pop();
        }
    }
    return days_go;
}


int solution()
{
    int days = distributed_BFS();
    int max_days = 0;
    for (int i = 0; i < tomato_box.size(); i++)
    {
        for (int j = 0; j < tomato_box[i].size(); j++)
        {
            if (tomato_box[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return days;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    tomato_box.resize(M);
    for (int i = 0; i < M; i++)
    {
        tomato_box[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            cin >> tomato_box[i][j];
            if (tomato_box[i][j] == 1)
                main_queue.push({ i, j });
        }
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}