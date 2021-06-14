#include <cstdio>
#include <vector>
using namespace std;

int test_case();
int read_input();
int print_output(long long result);
long long solution();
int T;
int N;
vector<long long> triangles;

int main()
{
    test_case();
    return 0;
}

long long solution()
{
    triangles.resize(101);
    triangles[1] = 1;
    triangles[2] = 1;
    triangles[3] = 1;
    triangles[4] = 2;
    triangles[5] = 2;
    for(int i = 6; i <= 100; i++)
    {
        triangles[i] = triangles[i-1] + triangles[i-5];
    }
    return 0;
}

int test_case()
{
    scanf("%d", &T);
    solution();
    for(int i = 0; i < T; i++)
    {
        read_input();
        print_output(triangles[N]);
    }
    return 0;
}

int read_input()
{
    scanf("%d", &N);
    return 0;
}

int print_output(long long result)
{
    printf("%lld\n", result);
    return 0;
}