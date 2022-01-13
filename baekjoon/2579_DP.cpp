#include <iostream>
#include <vector>

using namespace std;

enum
{
    ONE = 0,
    TWO,
};

int N;
vector<int> v_stair;
vector<vector<int>> v_DP;

void solution()
{
    cin >> N;
    v_stair.resize(N + 1);
    v_DP.resize(N + 1);
    for (auto &row : v_DP)
        row.resize(3);
    for (int i = 1; i <= N; i++)
    {
        cin >> v_stair[i];
    }

    v_DP[1][ONE] = v_stair[1];
    v_DP[1][TWO] = v_stair[1];
    for (int i = 2; i <= N; i++)
    {
        v_DP[i][ONE] = v_DP[i - 1][TWO] + v_stair[i];
        v_DP[i][TWO] = max(v_DP[i - 2][ONE], v_DP[i - 2][TWO]) + v_stair[i];
    }

    cout << max(v_DP[N][ONE], v_DP[N][TWO]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}