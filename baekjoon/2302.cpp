#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<long long> change_count;
vector<long long> not_change_count;
vector<bool> VIPs;

int solution()
{
    // input
    cin >> N >> M;
    change_count.resize(N + 1), 0;
    not_change_count.resize(N + 1, 0);
    VIPs.resize(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int vip_number;
        cin >> vip_number;
        VIPs[vip_number] = true;
    }

    // solution
    not_change_count[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        not_change_count[i] += change_count[i - 1];
        not_change_count[i] += not_change_count[i - 1];
        if (!VIPs[i] && !VIPs[i - 1])
        {
            change_count[i] += not_change_count[i - 1];
        }
    }

    // output
    cout << not_change_count[N] + change_count[N] << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}