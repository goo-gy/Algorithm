#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> factorial;

void calFactorial(int N)
{
    factorial.resize(N + 1, 1);
    for (int i = 1; i <= N; i++)
        factorial[i] = i * factorial[i - 1];
}

int solution()
{
    cin >> N >> K;
    calFactorial(N);
    cout << factorial[N] / (factorial[N - K] * factorial[K]) << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}