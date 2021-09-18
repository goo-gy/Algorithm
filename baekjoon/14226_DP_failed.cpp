#include <iostream>
#include <vector>

#define INF 1234567890

using namespace std;

int N;
int max_N;
vector<vector<int>> DP;

int find_min_count(int n, int copy)
{
    if (n > max_N || n <= 0)
        return INF;
    if (DP[n][copy] == INF + 1)
        return INF;
    if (DP[n][copy] != INF)
        return DP[n][copy];

    DP[n][copy] = INF + 1;
    int min_count = INF;
    min_count = min(min_count, find_min_count(n, n) + 1);
    min_count = min(min_count, find_min_count(n + copy, copy) + 1);
    min_count = min(min_count, find_min_count(n - 1, copy) + 1);
    DP[n][copy] = min_count;

    return min_count;
}

int solution()
{
    // input
    cin >> N;
    max_N = min(1000, 2*N);

    // solution
    DP.resize(max_N + 1);
    for (int i = 0; i <= max_N; i++)
    {
        DP[i].resize(max_N + 1, INF);
    }
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            DP[N][j] = 0;
        }
    }
    int result = find_min_count(1, 0);

    // output
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