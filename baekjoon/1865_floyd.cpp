#include <iostream>
#include <vector>
#include <tuple>

#define INF 1234567890

using namespace std;

int N, M, W;
vector<vector<long long>> vv_graph;

void floyd()
{
    for (int middle = 1; middle <= N; middle++)
    {
        for (int src = 1; src <= N; src++)
        {
            for (int dst = 1; dst <= N; dst++)
            {
                if (src == dst)
                    continue;
                int newDistance = vv_graph[src][middle] + vv_graph[middle][dst];
                if (newDistance < vv_graph[src][dst])
                    vv_graph[src][dst] = newDistance;
            }
        }
    }
}

void solution()
{
    cin >> N >> M >> W;
    vv_graph.resize(N + 1);
    for (auto &row : vv_graph)
        row.resize(N + 1, INF);
    for (int i = 1; i <= M; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        vv_graph[src][dst] = cost;
        vv_graph[dst][src] = cost;
    }
    floyd();
    bool canBack = false;
    for (int i = 1; i <= W; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        if (vv_graph[dst][src] < cost)
        {
            canBack = true;
            break;
        }
    }
    if (canBack)
        cout << "YES\n";
    else
        cout << "NO\n";
}

void reset()
{
    for (auto &row : vv_graph)
        row.clear();
    vv_graph.clear();
}

void test_case()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solution();
        reset();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_case();
    return 0;
}