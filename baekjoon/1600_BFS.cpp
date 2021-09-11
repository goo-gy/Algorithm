#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int MOVE[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int MOVE_HORSE[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int K, W, H;
int COL_END, ROW_END;
vector<vector<int>> map;
vector<vector<vector<bool>>> visited;

bool check_valid(int row, int col)
{
    if (row < 0 || col < 0 || row > ROW_END || col > COL_END || map[row][col] == 1)
        return false;
    return true;
}

int BFS(tuple<int, int, int, int> first)
{
    queue<tuple<int, int, int, int>> next_queue; // row, col, k, moves
    next_queue.push(first);
    int row, col, k, moves;
    while (!next_queue.empty())
    {
        tuple<int, int, int, int> current = next_queue.front();
        row = get<0>(current);
        col = get<1>(current);
        k = get<2>(current);
        moves = get<3>(current);
        next_queue.pop();

        if (!check_valid(row, col) || visited[row][col][k])
            continue;
        if (row == ROW_END && col == COL_END)
            return moves;
        
        visited[row][col][k] = true;

        if (k > 0)
        {
            for (int i = 0; i < 8; i++)
            {
                next_queue.push(make_tuple(row + MOVE_HORSE[i][0], col + MOVE_HORSE[i][1], k - 1, moves + 1));
            }
        }
        for (int i = 0; i < 4; i++)
        {
            next_queue.push(make_tuple(row + MOVE[i][0], col + MOVE[i][1], k, moves + 1));
        }
    }
    return -1;
}

int solution()
{
    // input
    cin >> K >> W >> H;
    COL_END = W - 1;
    ROW_END = H - 1;
    map.resize(H);
    visited.resize(H);
    for (int i = 0; i < H; i++)
    {
        map[i].resize(W);
        visited[i].resize(W);
        for (int j = 0; j < W; j++)
        {
            cin >> map[i][j];
            visited[i][j].resize(K+1, false);
        }
    }

    // solution
    int answer = BFS(make_tuple(0, 0, K, 0));

    // output
    cout << answer << '\n';

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}