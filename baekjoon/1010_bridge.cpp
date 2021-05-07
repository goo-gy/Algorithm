#include <cstdio>
#include <vector>
using namespace std;

int test_case();
int read_input();
int print_output(long long result);
long long solution();
int T;
long long N, M;

int main()
{
    test_case();
    return 0;
}

long long nCr(long long n, long long r)
{
    if(r == 0)
        return 1;
    return nCr(n, r-1)*(n-r+1)/r;
}

long long solution()
{
    long long bigger = max(N, M);
    long long smaller = min(N, M);
    return nCr(bigger, smaller);
}

int test_case()
{
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        read_input();
        long long result = solution();
        print_output(result);
    }
}

int read_input()
{
    scanf("%lld %lld", &N, &M);
    return 0;
}

int print_output(long long result)
{
    printf("%lld\n", result);
    return 0;
}