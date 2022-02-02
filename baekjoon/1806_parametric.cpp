#include <iostream>
#include <vector>

#define INF 1234567890

using namespace std;

int N, S;
vector<int> v_num;

void solution()
{
    cin >> N >> S;
    v_num.resize(N);
    for (int &num : v_num)
        cin >> num;

    int L = 0, R = -1;
    long long sum = 0;
    int minLen = INF;
    while (R < N)
    {
        if (sum >= S)
        {
            minLen = min(minLen, R - L + 1);
            sum -= v_num[L];
            L++;
        }
        else
        {
            R++;
            sum += v_num[R];
        }
    }
    if (minLen == INF)
        cout << "0\n";
    else
        cout << minLen << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}