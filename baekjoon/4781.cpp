#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define END -1
#define PRICE first
#define CALORY second

int solution()
{
    int N, M;
    double money;
    vector<pair<int, int>> v_candy;
    vector<int> DP;

    // input
    cin >> N >> money;
    M = int(money * 100);
    if(N == 0 && M == 0)
        return END;

    DP.resize(M + 1, 0);
    v_candy.resize(N);
    for (int i = 0; i < N; i++)
    {
        int calory;
        double price;
        cin >> calory >> price;
        v_candy[i] = make_pair(int(price * 100), calory);
    }

    // solution
    for(auto &candy : v_candy)
        DP[candy.PRICE] = max(DP[candy.PRICE], candy.CALORY);
    for (int i = 1; i <= M; i++)
    {
        int half = i/2;
        for(int less = 1; less <= half; less++)
            DP[i] = max(DP[i], DP[less] + DP[i - less]);
    }

    // output
    cout << DP[M] << "\n";

    return 0;
}

int test_case()
{
    while(true)
    {
        int result = solution();
        if(result == -1)
            return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_case();
    return 0;
}