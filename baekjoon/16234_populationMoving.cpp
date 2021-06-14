#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int read_input();
int print_output(long long result);
long long solution();
int N, L, R;
vector<vector<int>> pop_map;

struct Point
{
    int row, col;
};

Point MOVES[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
    read_input();
    long long result = solution();
    print_output(result);
    return 0;
}

bool is_valid_location(Point point)
{
    if(point.row >= 0 && point.col >= 0 && point.row < N && point.col < N)
        return true;
    else
        return false;
}

pair<int,int> BFS(vector<vector<int>> &visited, Point start_point, int group_number)
{
    queue<Point> next_queue;
    next_queue.push(start_point);
    int pop_sum = 0;
    int count = 0;
    while (!next_queue.empty())
    {
        Point current = next_queue.front();
        next_queue.pop();
        pop_sum += pop_map[current.row][current.col];
        count += 1;
        visited[current.row][current.col] = group_number;

        for(int i = 0; i < 4; i++)
        {
            Point next = {current.row + MOVES[i].row, current.col + MOVES[i].col};
            if(is_valid_location(next))
            {
                int gap = abs(pop_map[current.row][current.col] - pop_map[next.row][next.col]);
                if(gap >= L && gap <= R && !visited[next.row][next.col])
                {
                    next_queue.push(next);
                    visited[next.row][next.col] = group_number;
                }
            }
        }
    }
    return make_pair(pop_sum, count);
}

long long solution()
{
    int move_count = 0;
    while (true)
    {
        vector<vector<int>> visited(N, vector<int>(N, 0));
        int group_number = 1;
        vector<int> avg_groups(1);
        bool have_group = false;

        for (int row = 0; row < N; row++)
        {
            pop_map[row].resize(N);
            for (int col = 0; col < N; col++)
            {
                if (!visited[row][col])
                {
                    pair<int, int> result = BFS(visited, {row, col}, group_number);
                    if(result.second > 1)
                        have_group = true;
                    avg_groups.push_back(result.first / result.second);
                    group_number++;
                }
            }
        }
        if(have_group)
            move_count++;
        else
            break;
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                int group = visited[row][col];
                if(group)
                    pop_map[row][col] = avg_groups[group];
            }
        }
    }
    return move_count;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> R;
    pop_map.resize(N);
    for (int row = 0; row < N; row++)
    {
        pop_map[row].resize(N);
        for (int col = 0; col < N; col++)
        {
            cin >> pop_map[row][col];
        }
    }
    return 0;
}

int print_output(long long result)
{
    cout << result << "\n";
    return 0;
}