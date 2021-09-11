#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<vector<int>> board;
vector<vector<int>> candy_board;


int solution()
{
    cin >> R >> C;

    board.resize(R + 1);
    candy_board.resize(R + 1);
    for (int i = 1; i <= R; i++)
    {
        board[i].resize(C + 1);
        candy_board[i].resize(C + 1);
        for (int j = 1; j <= C; j++)
        {
            cin >> board[i][j];
        }
    }

    // solution
    candy_board[0].resize(C+1);
    for (int i = 1; i <= C; i++)
    {
        candy_board[1][i] = candy_board[1][i - 1] + board[1][i];
    }
    for (int i = 1; i <= R; i++)
    {
        candy_board[i][1] = candy_board[i - 1][1] + board[i][1];
    }
    for (int r = 2; r <= R; r++)
    {
        for (int c = 2; c <= C; c++)
        {
            candy_board[r][c] = max(candy_board[r - 1][c], candy_board[r][c - 1]) + board[r][c];
        }
    }

    // output
    cout << candy_board[R][C] << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}