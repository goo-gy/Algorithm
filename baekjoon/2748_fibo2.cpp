#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(long long result);
long long solution();
int N;
vector<long long> fibo;

int main()
{
    read_input();
    long long result = solution();
    print_output(result);
    return 0;
}

long long solution()
{
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[N];
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    fibo.resize(N+1);
    return 0;
}

int print_output(long long result)
{
    cout << result << endl;
    return 0;
}