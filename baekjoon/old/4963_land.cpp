#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int test_case();
int read_input();
int print_output(long long result);
long long solution();
int T;
int N, M;
int map[50][50];
struct Point
{
    int row, col;
};
queue<Point> land_list;

Point moves[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};

int main()
{
    test_case();
    return 0;
}

bool check_range(Point p)
{
    return (p.row >= 0 && p.col >= 0 && p.row < N && p.col < M);
}

int BFS(Point start)
{
    if(map[start.row][start.col] == 0)
        return 0;
    queue<Point> land_queue;
    land_queue.push(start);
    while(!land_queue.empty())
    {
        Point current = land_queue.front();
        land_queue.pop();

        for (int i = 0; i < 8; i++)
        {
            Point next = { current.row + moves[i].row, current.col + moves[i].col };
            if (check_range(next) && map[next.row][next.col] == 1)
            {
                map[next.row][next.col] = 0;
                land_queue.push(next);
            }
        }
    }
    return 1;
}

long long solution()
{
    int count = 0;
    while(!land_list.empty())
    {
        count += BFS(land_list.front());
        land_list.pop();
    }
    return count;
}

int test_case()
{
    scanf("%d %d", &M, &N);
    while(!(M == 0 && N == 0))
    {
        read_input();
        long long result = solution();
        print_output(result);
        scanf("%d %d", &M, &N);
    }
    return 0;
}

int read_input()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1)
                land_list.push({i, j});
        }
    }
    return 0;
}

int print_output(long long result)
{
    printf("%lld\n", result);
    return 0;
}