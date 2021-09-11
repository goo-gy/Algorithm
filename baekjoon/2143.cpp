#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long target, N, M;
vector<long long> A, B;
vector<long long> sum_A, sum_B;
map<long long, long long> sum_A_count;

int solution()
{
    // input
    cin >> target;
    cin >> N;
    A.resize(N + 1, 0);
    sum_A.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        sum_A[i] = sum_A[i - 1] + A[i];
    }
    cin >> M;
    B.resize(M + 1, 0);
    sum_B.resize(M + 1, 0);
    for (int i = 1; i <= M; i++)
    {
        cin >> B[i];
        sum_B[i] = sum_B[i - 1] + B[i];
    }

    // solution
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            long long value = sum_A[j] - sum_A[i - 1];
            map<long long, long long>::iterator iter = sum_A_count.find(value);
            if (iter == sum_A_count.end())
                sum_A_count[value] = 1;
            else
                iter->second = iter->second + 1;
        }
    }

    long long answer_count = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int j = i; j <= M; j++)
        {
            long long value = target - (sum_B[j] - sum_B[i - 1]);
            map<long long, long long>::iterator iter = sum_A_count.find(value);
            if (iter != sum_A_count.end())
                answer_count += iter->second;
        }
    }

    // output
    cout << answer_count << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}