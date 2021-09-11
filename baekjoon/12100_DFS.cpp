#include <iostream>
#include <vector>
using namespace std;

enum DIRECTION
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

int N;
int board[20][20];
// vector<vector<int>> board;

int slide(int direction)
{
    switch (direction)
    {
    case UP:
        for (int j = 0; j < N; j++)
        {
            vector<int> blocks;
            for (int i = 0; i < N; i++)
            {
                if (board[i][j])
                {
                    blocks.push_back(board[i][j]);
                }
                board[i][j] = 0;
            }
            int prev = -1;
            int i = 0;
            for (int k = 0; k < blocks.size(); k++)
            {
                if (prev == blocks[k])
                {
                    i--;
                    board[i][j] = 2 * prev;
                    prev = -1;
                }
                else
                {
                    board[i][j] = blocks[k];
                    prev = blocks[k];
                }
                i++;
            }
        }
        break;
    case RIGHT:
        for (int i = 0; i < N; i++)
        {
            vector<int> blocks;
            for (int j = N - 1; j >= 0; j--)
            {
                if (board[i][j])
                {
                    blocks.push_back(board[i][j]);
                }
                board[i][j] = 0;
            }
            int prev = -1;
            int j = N - 1;
            for (int k = 0; k < blocks.size(); k++)
            {
                if (prev == blocks[k])
                {
                    j++;
                    board[i][j] = 2 * prev;
                    prev = -1;
                }
                else
                {
                    board[i][j] = blocks[k];
                    prev = blocks[k];
                }
                j--;
            }
        }
        break;
    case DOWN:
        for (int j = 0; j < N; j++)
        {
            vector<int> blocks;
            for (int i = N - 1; i >= 0; i--)
            {
                if (board[i][j])
                {
                    blocks.push_back(board[i][j]);
                }
                board[i][j] = 0;
            }
            int prev = -1;
            int i = N - 1;
            for (int k = 0; k < blocks.size(); k++)
            {
                if (prev == blocks[k])
                {
                    i++;
                    board[i][j] = 2 * prev;
                    prev = -1;
                }
                else
                {
                    board[i][j] = blocks[k];
                    prev = blocks[k];
                }
                i--;
            }
        }
        break;
    case LEFT:
        for (int i = 0; i < N; i++)
        {
            vector<int> blocks;
            for (int j = 0; j < N; j++)
            {
                if (board[i][j])
                {
                    blocks.push_back(board[i][j]);
                }
                board[i][j] = 0;
            }
            int prev = -1;
            int j = 0;
            for (int k = 0; k < blocks.size(); k++)
            {
                if (prev == blocks[k])
                {
                    j--;
                    board[i][j] = 2 * prev;
                    prev = -1;
                }
                else
                {
                    board[i][j] = blocks[k];
                    prev = blocks[k];
                }
                j++;
            }
        }
        break;
    }
    return 0;
}

int max_value = -1;

void update_max()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            max_value = max(max_value, board[i][j]);
        }
    }
}

void DFS(int depth)
{
    if (depth > 5)
        return;
    int copy[20][20];
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            copy[row][col] = board[row][col];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        slide(i);
        update_max();
        DFS(depth + 1);
        // restore
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                board[row][col] = copy[row][col];
            }
        }
    }
}

int solution()
{
    // input
    cin >> N;
    // board.resize(N);
    for (int i = 0; i < N; i++)
    {
        // board[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    // solution
    DFS(1);

    // output
    cout << max_value << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}