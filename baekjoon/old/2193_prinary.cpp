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
    fibo.resize(N);
    fibo[0] = 1;
    if(N > 1)
        fibo[1] = 1;
    for(int i = 2; i < N; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[N-1];
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    return 0;
}

int print_output(long long result)
{
    cout << result << endl;
    return 0;
}