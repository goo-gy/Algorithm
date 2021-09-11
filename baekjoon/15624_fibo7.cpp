#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> fibo_list;

int solution()
{
    // input
    cin >> N;

    // solution
    fibo_list.resize(N+1);
    fibo_list[0] = 0;
    fibo_list[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        fibo_list[i] = (fibo_list[i-1] + fibo_list[i-2])%1000000007;
    }

    // output
    cout << fibo_list[N] << "\n";

    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}