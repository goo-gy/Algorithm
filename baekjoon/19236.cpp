#include <iostream>
#include <vector>
#include <algorithm>

#define PII pair<int, int>
#define EMPTY 0
#define SHARK -1

using namespace std;

pair<int, int> moves[] = {
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
};

class Fish
{
public:
    int id;
    int direction;
    pair<int, int> position;
    bool operator<(const Fish &other) const
    {
        return this->id < other.id;
    }
};

class Shark
{
public:
    int direction;
    int sum = 0;
    pair<int, int> position;
};

int N = 4;
vector<vector<int>> vv_map;
vector<Fish> v_fish(1);
Shark shark;
int maxSum = 0;

bool check_range(pair<int, int> p)
{
    return (p.first >= 0 && p.second >= 0 && p.first < N && p.second < N);
}

void moveFish(Fish &fish)
{
    if (fish.id == SHARK)
        return;

    PII current = fish.position;
    while (true)
    {
        PII move = moves[fish.direction];
        PII next = make_pair(current.first + move.first, current.second + move.second);
        if (check_range(next) && vv_map[next.first][next.second] != SHARK)
        {
            Fish &other = v_fish[vv_map[next.first][next.second]];

            vv_map[next.first][next.second] = fish.id;
            vv_map[current.first][current.second] = other.id;

            fish.position = next;
            other.position = current;
            break;
        }
        fish.direction = (fish.direction + 1) % 8;
    }
}

bool firstTime = true;
bool moveShark(pair<int, int> dst)
{
    if (!firstTime)
        vv_map[shark.position.first][shark.position.second] = EMPTY;

    Fish &fish = v_fish[vv_map[dst.first][dst.second]];

    shark.sum += fish.id;
    shark.direction = fish.direction;
    shark.position = dst;

    fish.id = SHARK;
    vv_map[dst.first][dst.second] = SHARK;
    firstTime = false;
    return true;
}

void DFS(PII position)
{
    vector<vector<int>> vv_mapBackUp = vv_map;
    vector<Fish> v_fishBackUp = v_fish;
    Shark sharkBackUp = shark;

    //
    moveShark(position);
    for (int i = 1; i < v_fish.size(); i++)
    {
        moveFish(v_fish[i]);
    }
    PII move = moves[shark.direction];
    for (int i = 1; i <= 3; i++)
    {
        PII next = make_pair(shark.position.first + move.first * i, shark.position.second + move.second * i);
        if (check_range(next) && vv_map[next.first][next.second] != EMPTY)
            DFS(next);
    }
    maxSum = max(maxSum, shark.sum);

    v_fish = v_fishBackUp;
    shark = sharkBackUp;
    vv_map = vv_mapBackUp;
}

void solution()
{
    v_fish[0].id = 0;
    vv_map.resize(N);
    for (auto &row : vv_map)
        row.resize(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Fish fish;
            cin >> fish.id >> fish.direction;
            fish.direction--;
            fish.position = make_pair(i, j);
            v_fish.push_back(fish);
            vv_map[i][j] = fish.id;
        }
    }
    sort(v_fish.begin(), v_fish.end());
    DFS(make_pair(0, 0));
    cout << maxSum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}