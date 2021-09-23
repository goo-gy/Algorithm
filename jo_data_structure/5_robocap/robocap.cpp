#include <vector>
#include <iostream>

#define X first
#define Y second

using namespace std;

int N;
vector<pair<int, int>> v_point;
vector<pair<int, int>> v_time_to_position;

int total_length = 0;
int curr_time = 0;

void find_position(int prev, int curr)
{
    int x_gap = v_point[curr].X - v_point[prev].X;
    int y_gap = v_point[curr].Y - v_point[prev].Y;
    int x_mov = x_gap < 0 ? -1 : 1;
    int y_mov = y_gap < 0 ? -1 : 1;
    for (int go = v_point[prev].X; go != v_point[curr].X; go += x_mov)
    {
        v_time_to_position[curr_time] = {go, v_point[prev].Y};
        curr_time++;
    }
    for (int go = v_point[prev].Y; go != v_point[curr].Y; go += y_mov)
    {
        v_time_to_position[curr_time] = {v_point[prev].X, go};
        curr_time++;
    }
}

void solution()
{
    int prev = 0;
    for (int curr = 1; curr < N; curr++)
    {
        find_position(prev, curr);
        prev = curr;
    }
    find_position(N - 1, 0);
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N;
    int x, y, prev_x, prev_y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v_point.push_back({x, y});
        if (i != 0)
            total_length += abs(x - prev_x) + abs(y - prev_y);
        prev_x = x;
        prev_y = y;
    }
    total_length += abs(v_point[0].X - v_point[N - 1].X) + abs(v_point[0].Y - v_point[N - 1].Y);
    v_time_to_position.resize(total_length);
}

void output()
{
    for (int i = 0; i < 5; i++)
    {
        int time;
        cin >> time;
        time %= total_length;
        cout << v_time_to_position[time].X << " " << v_time_to_position[time].Y << "\n";
    }
}

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}