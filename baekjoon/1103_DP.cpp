#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool isLoop = false;
vector<vector<int>> vv_board;
vector<vector<bool>> vv_visited;
vector<vector<int>> vv_DP;

#define HOLE -1
#define NOTSET - 1


bool isOutBoard(int row, int col)
{
    if(row < 0 || col < 0 || row >= N || col >= M)
        return true;
    return false;
}

int DFS(int row, int col)
{
    // base
    if(isOutBoard(row, col) || vv_board[row][col] == HOLE)
        return 0;

    // vv_DP
    if(vv_DP[row][col] != NOTSET)
        return vv_DP[row][col];

    // DFS
    if(vv_visited[row][col])
    {
        isLoop = true;
        return -1;
    }
    vv_visited[row][col] = true;

    int X = vv_board[row][col];
    int result = 0;
    result = max(result, DFS(row + X, col));
    result = max(result, DFS(row - X, col));
    result = max(result, DFS(row, col + X));
    result = max(result, DFS(row, col - X));
    vv_DP[row][col] = result + 1;
    
    vv_visited[row][col] = false;
    return vv_DP[row][col];
}

int solution()
{
    // input
    cin >> N >> M;
    vv_board.resize(N);
    vv_DP.resize(N);
    vv_visited.resize(N);
    for (int i = 0; i < N; i++)
    {
        vv_board[i].resize(M);
        vv_DP[i].resize(M, NOTSET);
        vv_visited[i].resize(M, false);
        string str_row;
        cin >> str_row;
        for(int j = 0; j < M; j++)
        {
            if(str_row[j] == 'H')
                vv_board[i][j] = HOLE;
            else 
                vv_board[i][j] = str_row[j] - '0';
        }
    }

    // solution
    int result = DFS(0, 0);
    if(isLoop)
        cout << "-1\n";
    else
        cout << result << "\n";
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}