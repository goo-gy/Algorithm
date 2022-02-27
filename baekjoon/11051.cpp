#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> DP;

int getCombination(int N, int K)
{
    if(DP[N][K] != -1)
        return DP[N][K];
    if(N == K || K == 0)
        return 1;
    DP[N][K] = (getCombination(N - 1, K - 1) + getCombination(N - 1, K)) % 10007;
    return DP[N][K];
}

int solution()
{
    int N, K;
    cin >> N >> K;
    DP.resize(N + 1);
    for(auto &row : DP)
        row.resize(N + 1, -1);
    
    cout << getCombination(N, K) << "\n";
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}