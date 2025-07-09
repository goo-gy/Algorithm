#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <tuple>

#define GET_BIT(x) (1 << x)
#define MAX_COUNT 16
#define MAX_SPACE (2 << MAX_COUNT)
#define INF 0xFFFFFFFF

int N;
__uint32_t w[MAX_COUNT][MAX_COUNT];
__uint32_t dp[MAX_SPACE][MAX_COUNT];

using namespace std;

void get_input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
}

int solution()
{
    memset(dp, 0xFF, sizeof(int) * MAX_SPACE * MAX_COUNT);
    queue<tuple<__uint32_t, int>> queue; // visited, current

    __uint32_t prev_visited = GET_BIT(0);
    int prev = 0;
    dp[prev_visited][prev] = 0;
    for (int i = 1; i < N; i++)
    {
        dp[GET_BIT(i) + prev_visited][i] = w[0][i];
        queue.push(make_tuple(GET_BIT(i) + prev_visited, i));
    }
    while (!queue.empty())
    {
        // TODO : check visited
        tuple<__uint32_t, int> _current = queue.front();
        queue.pop();
        __uint32_t visited = get<0>(_current);
        int current = get<1>(_current);

        prev_visited = visited - GET_BIT(current);
        if (prev_visited <= 0)
            continue;
        int max_bit = GET_BIT((N - 1));
        for (int prev = 1; prev <= max_bit; prev++)
        {
            __uint32_t prev_bit = GET_BIT(prev);
            if (prev_visited & prev_bit)
            {
                dp[visited][current] = min(dp[visited][current], dp[prev_visited][prev] + w[prev][current]);
            }
            else if (prev < N && prev != current)
            {
                queue.push(make_tuple(visited + prev_bit, prev)); // prev is next here
            }
        }
    }

    int visited_all = GET_BIT(N) - 1;
    __uint32_t result = dp[visited_all][1] + w[1][0];
    for (int i = 1; i < N; i++)
    {
        result = min(result, dp[visited_all][i] + w[i][0]);
    }
    printf("%d\n", result);
    return 0;
}

int main()
{
    get_input();
    solution();
    return 0;
}