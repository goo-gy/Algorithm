#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1234567890
#define PII pair<int, int>
#define COST first
#define NODE second

int N, M, X;
vector<vector<PII>> graphForward;
vector<vector<PII>> graphReverse;
vector<int> v_distanceForward;
vector<int> v_distanceReverse;

void dijkstra(vector<vector<PII>> &graph, vector<int> &v_distance)
{
    vector<bool> v_visitied(N + 1);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, X));
    v_distance[X] = 0;

    while (!pq.empty())
    {
        PII current = pq.top();
        pq.pop();
        if (v_visitied[current.NODE])
            continue;
        v_visitied[current.NODE] = true;
        for (PII next : graph[current.NODE])
        {
            int updateDistance = v_distance[current.NODE] + next.COST;
            if (!v_visitied[next.NODE] && updateDistance < v_distance[next.NODE])
            {
                v_distance[next.NODE] = updateDistance;
                pq.push(make_pair(updateDistance, next.NODE));
            }
        }
    }
}

int solution()
{
    cin >> N >> M >> X;
    graphForward.resize(N + 1);
    graphReverse.resize(N + 1);
    v_distanceForward.resize(N + 1, INF);
    v_distanceReverse.resize(N + 1, INF);
    for (int i = 1; i <= M; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        graphForward[src].push_back(make_pair(cost, dst));
        graphReverse[dst].push_back(make_pair(cost, src));
    }
    dijkstra(graphForward, v_distanceForward);
    dijkstra(graphReverse, v_distanceReverse);

    int maxCost = 0;
    for (int i = 1; i <= N; i++)
        maxCost = max(maxCost, v_distanceForward[i] + v_distanceReverse[i]);
    cout << maxCost << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}