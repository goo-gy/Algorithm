#include <cstdio>
#include <cstring>
#include <queue>

#define MAX_COUNT 16
#define MAX_SPACE (1 << MAX_COUNT)
#define GET_BIT(X) (1 << X)
#define INF 0xFFFFFF

int N;
__uint32_t w[MAX_COUNT][MAX_COUNT];
__uint32_t dp[MAX_SPACE][MAX_COUNT];

using namespace std;

class Route
{
public:
    __uint32_t visited;
    __uint32_t position;

    Route(__uint32_t _visited, __uint32_t _position)
    {
        this->visited = _visited;
        this->position = _position;
    }
};

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
    memset(dp, -1, sizeof(__uint32_t) * MAX_SPACE * MAX_COUNT);
    queue<Route> q;
    q.push(Route(GET_BIT(0), 0));
    dp[1][0] = 0;
    while (!q.empty())
    {
        Route current = q.front();
        q.pop();
        for (size_t next = 0; next < N; next++)
        {
            if (w[current.position][next] == 0)
                continue;
            __uint32_t targetBit = GET_BIT(next);
            if (current.visited & targetBit)
                continue;
            __uint32_t nextVisited = current.visited | targetBit;
            __uint32_t newDistance = dp[current.visited][current.position] + w[current.position][next];
            if (newDistance < dp[nextVisited][next])
            {
                dp[nextVisited][next] = newDistance;
                q.push(Route(nextVisited, next));
            }
        }
    }
    __uint32_t visitedAll = GET_BIT(N) - 1;
    __uint32_t result = INF;
    for (size_t i = 1; i < N; i++)
    {
        if (w[i][0] == 0 || dp[visitedAll][i] == 0xFFFFFFFF)
            continue;
        result = min(result, dp[visitedAll][i] + w[i][0]);
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