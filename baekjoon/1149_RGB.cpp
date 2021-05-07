#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<vector<int>> painted_minimum;

#define R 0
#define G 1
#define B 2

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    painted_minimum.resize(N, {0, 0, 0});
    scanf("%d %d %d", &painted_minimum[0][R], &painted_minimum[0][G], &painted_minimum[0][B]);

    int RGB[3];
    for(int i = 1; i < N; i++)
    {
        scanf("%d %d %d", &RGB[R], &RGB[G], &RGB[B]);
        
        for(int color = 0; color < 3; color++)
        {
            painted_minimum[i][color] = RGB[color] + min(painted_minimum[i - 1][(color + 1)%3], painted_minimum[i - 1][(color + 2)%3]);
        }
    }
    return min(min(painted_minimum[N-1][R], painted_minimum[N-1][G]), painted_minimum[N-1][B]);
}

int read_input()
{
    scanf("%d", &N);
    return 0;
}

int print_output(int result)
{
    printf("%d\n", result);
    return 0;
}