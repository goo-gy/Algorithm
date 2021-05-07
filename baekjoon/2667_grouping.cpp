#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <fstream>

using namespace std;

struct Point
{
    int row, col;
};

Point moves[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int read_file();
int read_input();
int print_output(int result);
int solution();
int N, M;
vector<vector<int>> tomato_box;
vector<vector<int>> days_map;
vector<vector<bool>> visited;
vector<Point> start_list;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

bool check_range(Point p)
{
    return (p.row >= 0 && p.col >= 0 && p.row < M && p.col < N);
}

void reset_visited()
{
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            visited[i][j] = false;
        }
    }
}

int distributed_BFS()
{
    int K = start_list.size();
    vector<queue<Point>> queue_list = vector<queue<Point>>(K);
    for (int i = 0; i < K; i++)
    {
        queue_list[i].push(start_list[i]);
        days_map[start_list[i].row][start_list[i].col] = 0;
        visited[start_list[i].row][start_list[i].col] = true;
    }

    bool all_empty = true;
    do
    {
        // distributed
        all_empty = true;
        for (int q = 0; q < K; q++)
        {
            if(queue_list[q].empty())
                continue;
            Point current = queue_list[q].front();
            queue_list[q].pop();
            // moves
            for (int i = 0; i < 4; i++)
            {
                Point next = { current.row + moves[i].row, current.col + moves[i].col };
                if (check_range(next) && tomato_box[next.row][next.col] == 0 && visited[next.row][next.col] == false)
                {
                    int update_days = days_map[current.row][current.col] + 1;
                    if( update_days < days_map[next.row][next.col])
                    {
                        days_map[next.row][next.col] = update_days;
                        queue_list[q].push(next);
                    }
                    visited[next.row][next.col] = true;
                }
            }
            if(!queue_list[q].empty())
                all_empty = false;
        }
    } while (!all_empty);
    return 0;
}



void show()
{
    for (int i = 0; i < tomato_box.size(); i++)
    {
        for (int j = 0; j < tomato_box[i].size(); j++)
        {
            cout << tomato_box[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            cout << days_map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int solution()
{
    distributed_BFS();
    int max_days = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            if (tomato_box[i][j] == -1)
            {
                continue;
            }
            if (days_map[i][j] == INT_MAX)
                return -1;
            if (max_days < days_map[i][j])
                max_days = days_map[i][j];
        }
    }
    return max_days;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    tomato_box.resize(M);
    days_map.resize(M);
    visited.resize(M);
    for (int i = 0; i < M; i++)
    {
        tomato_box[i].resize(N);
        days_map[i].resize(N, INT_MAX);
        visited[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            cin >> tomato_box[i][j];
            if (tomato_box[i][j] == 1)
                start_list.push_back({ i, j });
        }
    }
    return 0;
}

int read_file()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream input_file("input.txt");
    if(input_file.is_open())
    {
        input_file >> N >> M;
        tomato_box.resize(M);
        days_map.resize(M);
        visited.resize(M);
        for (int i = 0; i < M; i++)
        {
            tomato_box[i].resize(N);
            days_map[i].resize(N, INT_MAX);
            visited[i].resize(N);
            for (int j = 0; j < N; j++)
            {
                input_file >> tomato_box[i][j];
                if (tomato_box[i][j] == 1)
                    start_list.push_back({ i, j });
            }
        }
        input_file.close();
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}