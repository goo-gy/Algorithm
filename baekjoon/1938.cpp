#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

enum
{
    ROW,
    COL,
    DIRECT,
    COUNT,
};
enum
{
    HORIZON,
    VERTICAL,
};

int N;
tuple<int, int, int> moves[] = {make_tuple(-1, 0, 0), make_tuple(0, 1, 0), make_tuple(1, 0, 0), make_tuple(0, -1, 0)};
tuple<int, int, int, int> pBegin, pEnd;
vector<vector<int>> vv_map;
vector<vector<vector<bool>>> vvv_visited;

void initialize_map()
{
    vv_map.resize(N + 1);
    vvv_visited.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        vv_map[i].resize(N + 1);
        vvv_visited[i].resize(N + 1);
        for (int j = 1; j <= N; j++)
            vvv_visited[i][j].resize(2);
    }
}

int check_end(tuple<int, int, int, int> p)
{
    return (get<ROW>(p) == get<ROW>(pEnd) && get<COL>(p) == get<COL>(pEnd) && get<DIRECT>(p) == get<DIRECT>(pEnd));
}

bool check_turn(tuple<int, int, int, int> p)
{
    if (get<ROW>(p) >= 2 && get<ROW>(p) < N && get<COL>(p) >= 2 && get<COL>(p) < N)
    {
        for (int i = get<ROW>(p) - 1; i <= get<ROW>(p) + 1; i++)
        {
            for (int j = get<COL>(p) - 1; j <= get<COL>(p) + 1; j++)
            {
                if (vv_map[i][j] == 1)
                    return false;
            }
        }
        return true;
    }
    return false;
}

bool check_valid(tuple<int, int, int, int> p)
{
    int minRow = 1, minCol = 1;
    int maxRow = N, maxCol = N;
    int rowInc = 0, colInc = 0;
    if (get<DIRECT>(p) == HORIZON)
    {
        minCol++;
        maxCol--;
        colInc = 1;
    }
    else
    {
        minRow++;
        maxRow--;
        rowInc = 1;
    }
    if (get<ROW>(p) >= minRow && get<ROW>(p) <= maxRow && get<COL>(p) >= minCol && get<COL>(p) <= maxCol)
    {
        int r = get<ROW>(p) - rowInc;
        int c = get<COL>(p) - colInc;
        while (r <= get<ROW>(p) + rowInc && c <= get<COL>(p) + colInc)
        {
            if (vv_map[r][c] == 1)
                return false;
            r += rowInc;
            c += colInc;
        }
        return true;
    }
    return false;
}

int BFS()
{
    queue<tuple<int, int, int, int>> q;
    q.push(pBegin);

    vvv_visited[get<ROW>(pBegin)][get<COL>(pBegin)][get<DIRECT>(pBegin)] = true;
    while (!q.empty())
    {
        tuple<int, int, int, int> current = q.front();
        q.pop();
        if (check_end(current))
            return get<COUNT>(current);
        for (auto move : moves)
        {
            tuple<int, int, int, int> next = {get<ROW>(current) + get<ROW>(move), get<COL>(current) + get<COL>(move), get<DIRECT>(current), get<COUNT>(current) + 1};
            if (check_valid(next) && !vvv_visited[get<ROW>(next)][get<COL>(next)][get<DIRECT>(next)])
            {
                vvv_visited[get<ROW>(next)][get<COL>(next)][get<DIRECT>(next)] = true;
                q.push(next);
            }
        }
        if (check_turn(current))
        {
            tuple<int, int, int, int> next = {get<ROW>(current), get<COL>(current), !get<DIRECT>(current), get<COUNT>(current) + 1};
            if (check_valid(next) && !vvv_visited[get<ROW>(next)][get<COL>(next)][get<DIRECT>(next)])
            {
                vvv_visited[get<ROW>(next)][get<COL>(next)][get<DIRECT>(next)] = true;
                q.push(next);
            }
        }
    }
    return 0;
}

void solution()
{
    cin >> N;
    initialize_map();
    vector<tuple<int, int>> v_bPoint, v_ePoint;
    for (int i = 1; i <= N; i++)
    {
        string row;
        cin >> row;
        int j = 1;
        for (char block : row)
        {
            if (block == '1')
                vv_map[i][j] = 1;
            else
            {
                vv_map[i][j] = 0;
                if (block == 'B')
                    v_bPoint.push_back(make_tuple(i, j));
                else if (block == 'E')
                    v_ePoint.push_back(make_tuple(i, j));
            }
            j++;
        }
    }
    if (get<ROW>(v_bPoint[0]) == get<ROW>(v_bPoint[1]))
        pBegin = make_tuple(get<ROW>(v_bPoint[1]), get<COL>(v_bPoint[1]), HORIZON, 0);
    else
        pBegin = make_tuple(get<ROW>(v_bPoint[1]), get<COL>(v_bPoint[1]), VERTICAL, 0);

    if (get<ROW>(v_ePoint[0]) == get<ROW>(v_ePoint[1]))
        pEnd = make_tuple(get<ROW>(v_ePoint[1]), get<COL>(v_ePoint[1]), HORIZON, 0);
    else
        pEnd = make_tuple(get<ROW>(v_ePoint[1]), get<COL>(v_ePoint[1]), VERTICAL, 0);

    cout << BFS() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}