#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> vv_DP;
vector<vector<int>> vv_triangle;

int solution()
{
    cin >> N;
    vv_DP.resize(N + 1);
    vv_triangle.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        vv_DP[i].resize(N + 2, 0);
        vv_triangle[i].resize(N + 1);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >> vv_triangle[i][j];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int prev = max(vv_DP[i - 1][j - 1], vv_DP[i - 1][j]);
            vv_DP[i][j] = prev + vv_triangle[i][j];
        }
    }
    int maxSum = 0;
    for (int i = 1; i <= N; i++)
    {
        maxSum = max(maxSum, vv_DP[N][i]);
    }
    cout << maxSum << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}