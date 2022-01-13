#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int N, M;
string str1, str2;
vector<vector<int>> vv_DP;
vector<vector<pair<int, int>>> vv_trace;

string getString()
{
    stack<char> s_LCS;
    string LCS;
    auto current = make_pair(N, M);
    while (current.first > 0 && current.second > 0)
    {
        auto next = vv_trace[current.first][current.second];
        if (current.first != next.first && current.second != next.second)
            s_LCS.push(str1[current.first - 1]);
        current = next;
    }
    while (!s_LCS.empty())
    {
        LCS += s_LCS.top();
        s_LCS.pop();
    }
    return LCS;
}

void solution()
{
    cin >> str1 >> str2;
    N = str1.size();
    M = str2.size();

    vv_DP.resize(N + 1);
    vv_trace.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        vv_DP[i].resize(str2.size() + 1);
        vv_trace[i].resize(str2.size() + 1);
    }

    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= M; col++)
        {
            if (vv_DP[row - 1][col] > vv_DP[row][col - 1])
            {
                vv_DP[row][col] = vv_DP[row - 1][col];
                vv_trace[row][col] = make_pair(row - 1, col);
            }
            else
            {
                vv_DP[row][col] = vv_DP[row][col - 1];
                vv_trace[row][col] = make_pair(row, col - 1);
            }
            if (str1[row - 1] == str2[col - 1] && vv_DP[row][col] < vv_DP[row - 1][col - 1] + 1)
            {
                vv_DP[row][col] = max(vv_DP[row][col], vv_DP[row - 1][col - 1] + 1);
                vv_trace[row][col] = make_pair(row - 1, col - 1);
            }
        }
    }
    string LCS = getString();
    cout << vv_DP[N][M] << "\n";
    if (vv_DP[N][M] > 0)
        cout << LCS << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}