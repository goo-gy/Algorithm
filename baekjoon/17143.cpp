#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum
{
    UP = 1,
    DOWN,
    RIGHT,
    LEFT
};

class Shark
{
public:
    int row, col;
    int speed, direction, size;
    bool live;
};

int R, C, M;
vector<vector<pair<int, int>>> vv_map; // sharkId, generation, size
vector<Shark> v_shark;
int sharkSize = 0;

void getShark(int time)
{
    for (int r = 1; r <= R; r++)
    {
        int sharkId = vv_map[r][time].first;
        if (sharkId != -1)
        {
            sharkSize += v_shark[sharkId].size;
            v_shark[sharkId].live = false;
            vv_map[r][time] = make_pair(-1, 0);
            break;
        }
    }
}

void move(int sharkId, int time)
{
    Shark &shark = v_shark[sharkId];
    if (!shark.live)
        return;
    auto &placePrev = vv_map[shark.row][shark.col];
    if (placePrev.first == sharkId)
        placePrev = make_pair(-1, 0);

    switch (shark.direction)
    {
    case UP:
        shark.row -= shark.speed;
        break;
    case DOWN:
        shark.row += shark.speed;
        break;
    case RIGHT:
        shark.col += shark.speed;
        break;
    case LEFT:
        shark.col -= shark.speed;
        break;
    }

    while (true)
    {
        if (shark.row <= 0)
        {
            shark.row = -shark.row + 2;
            shark.direction = DOWN;
        }
        else if (shark.row > R)
        {
            shark.row = R - (shark.row - R);
            shark.direction = UP;
        }
        else if (shark.col <= 0)
        {
            shark.col = -shark.col + 2;
            shark.direction = RIGHT;
        }
        else if (shark.col > C)
        {
            shark.col = C - (shark.col - C);
            shark.direction = LEFT;
        }
        else
            break;
    }

    auto &place = vv_map[shark.row][shark.col];
    if (place.first != -1 && place.second == time)
    {
        Shark &sharkOther = v_shark[place.first];
        if (shark.size > sharkOther.size)
        {
            sharkOther.live = false;
            place = make_pair(sharkId, time);
        }
        else
            shark.live = false;
    }
    else
        place = make_pair(sharkId, time);
}

void solution()
{
    cin >> R >> C >> M;
    vv_map.resize(R + 1);
    for (auto &v_row : vv_map)
        v_row.resize(C + 1, make_pair(-1, 0));
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        v_shark.push_back({r, c, s, d, z, true});
        vv_map[r][c] = make_pair(i, 0);
    }

    int time = 0;
    while (time < C)
    {
        time++;
        getShark(time);
        for (int i = 0; i < v_shark.size(); i++)
            move(i, time);
    }
    cout << sharkSize << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}