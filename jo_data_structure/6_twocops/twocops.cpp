#include <vector>
#include <iostream>

using namespace std;

int N, target_time;
struct Point
{
    int x;
    int y;
};
vector<Point> v_point;
vector<Point> v_time_to_p;
vector<Point> v_time_to_p1;
vector<Point> v_time_to_p2;

int total_length = 0;
int time_second_init = 0;

int time_save = 0;
void save_time_map(int prev, int curr)
{
    int x_gap = v_point[curr].x - v_point[prev].x;
    int y_gap = v_point[curr].y - v_point[prev].y;
    int x_mov = x_gap < 0 ? -1 : 1;
    int y_mov = y_gap < 0 ? -1 : 1;
    if (curr == N / 2)
        time_second_init = time_save;
    for (int go = v_point[prev].x; go != v_point[curr].x; go += x_mov)
    {
        v_time_to_p[time_save] = {go, v_point[prev].y};
        time_save++;
    }
    for (int go = v_point[prev].y; go != v_point[curr].y; go += y_mov)
    {
        v_time_to_p[time_save] = {v_point[prev].x, go};
        time_save++;
    }
}

void find_position_two()
{
    int time_first = 0;
    int time_second = time_second_init;
    int cur_time = 0;

    int direction = 1;
    while (cur_time < total_length)
    {
        v_time_to_p1[cur_time] = v_time_to_p[time_first];
        v_time_to_p2[cur_time] = v_time_to_p[time_second];
        cur_time++;
        if(abs(time_first - time_second) <= 1)
        {
            direction = -direction;
            if (abs(time_first - time_second) == 1)
            {
                v_time_to_p1[cur_time] = v_time_to_p[time_first];
                v_time_to_p2[cur_time] = v_time_to_p[time_second];
                cur_time++;
            }
        }
        time_first =  (time_first + direction + total_length) % total_length;
        time_second = (time_second - direction + total_length) % total_length;
    }
}

void solution()
{
    int prev = 0;
    for (int curr = 1; curr < N; curr++)
    {
        save_time_map(prev, curr);
        prev = curr;
    }
    save_time_map(N - 1, 0);
    find_position_two();
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
        Point point = {x, y};
        v_point.push_back(point);
        if (i != 0)
            total_length += abs(x - prev_x) + abs(y - prev_y);
        prev_x = x;
        prev_y = y;
    }
    total_length += abs(v_point[0].x - v_point[N - 1].x) + abs(v_point[0].y - v_point[N - 1].y);
    v_time_to_p.resize(total_length);
    v_time_to_p1.resize(total_length);
    v_time_to_p2.resize(total_length);
    cin >> target_time;
}

void output()
{
    target_time %= total_length;
    cout << v_time_to_p1[target_time].x << " " << v_time_to_p1[target_time].y << "\n";
    cout << v_time_to_p2[target_time].x << " " << v_time_to_p2[target_time].y << "\n";
}

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}