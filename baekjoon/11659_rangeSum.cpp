#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v_sum;

void solution()
{
    cin >> N >> M;
    v_sum.resize(N + 1);
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        v_sum[i] = v_sum[i - 1] + num;
    }
    for (int i = 1; i <= M; i++)
    {
        int begin, end;
        cin >> begin >> end;
        cout << v_sum[end] - v_sum[begin - 1] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}