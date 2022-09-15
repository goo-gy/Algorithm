#include <iostream>
#include <vector>

#define MAX_N 10000

using namespace std;

int DP[MAX_N][4];

int solution()
{
    // solution
    DP[1][2] = 1;
    DP[1][3] = 1;
    DP[2][2] = 2;
    DP[2][3] = 2;
    DP[3][2] = 2;
    DP[3][3] = 3;

    for(int i = 4; i <= MAX_N; i++)
    {
        DP[i][1] = 1;
        DP[i][2] = DP[i][1] + DP[i - 2][2];
        DP[i][3] = DP[i][2] + DP[i - 3][3];
    }

    // output
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        cout << DP[N][3] << " \n";
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}