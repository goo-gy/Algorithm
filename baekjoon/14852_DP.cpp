#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> use_none;
vector<long long> use_top;
vector<long long> use_bottom;
vector<long long> use_all;

int solution()
{
    // input
    cin >> N;

    // solution
    use_none.resize(N);
    use_top.resize(N);
    use_bottom.resize(N);
    use_all.resize(N);

    use_none[0] = 1;
    use_top[0] = 1;
    use_bottom[0] = 1;
    use_all[0] = 2;
    for (int i = 1; i < N; i++)
    {
        use_none[i] = (use_all[i - 1]) % 1000000007;
        use_top[i] = (use_all[i - 1] + use_bottom[i - 1]) % 1000000007;
        use_bottom[i] = (use_all[i - 1] + use_top[i - 1]) % 1000000007;
        use_all[i] = (use_all[i - 1] * 2 + use_none[i - 1] + use_top[i - 1] + use_bottom[i - 1]) % 1000000007;
    }
    // output
    cout << (use_all[N - 1]) % 1000000007 << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}