#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<bool>> graph;

void floyd()
{
    for (int middle = 1; middle <= N; middle++)
    {
        for (int src = 1; src <= N; src++)
        {
            for (int dst = 1; dst <= N; dst++)
            {
                if (graph[src][middle] && graph[middle][dst])
                    graph[src][dst] = true;
            }
        }
    }
}

int solution()
{
    cin >> N >> M;
    graph.resize(N + 1);
    for (auto &row : graph)
        row.resize(N + 1, false);
    for (int i = 1; i <= M; i++)
    {
        int src, dst;
        cin >> src >> dst;
        graph[src][dst] = true;
    }

    floyd();
    int knowCount = 0;
    for (int src = 1; src <= N; src++)
    {
        bool know = true;
        for (int dst = 1; dst <= N; dst++)
        {
            if (!graph[src][dst] && !graph[dst][src] && src != dst)
                know = false;
        }
        if (know)
            knowCount++;
    }
    cout << knowCount << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}