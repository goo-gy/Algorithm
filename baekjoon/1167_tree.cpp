#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1234567890
#define COST first
#define NODE second

int N;
vector<vector<pair<int, int>>> vv_graph;

pair<int, int> findFarthest(int start)
{
    vector<int> v_distance(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    v_distance[start] = 0;
    pq.push(make_pair(0, start));

    pair<int, int> farthest = make_pair(0, 0);
    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
        if (current.COST > farthest.COST)
            farthest = current;
        for (auto next : vv_graph[current.NODE])
        {
            int newDistance = v_distance[current.NODE] + next.COST;
            if (newDistance < v_distance[next.NODE])
            {
                v_distance[next.NODE] = newDistance;
                pq.push(make_pair(newDistance, next.NODE));
            }
        }
    }
    return farthest;
}

void solution()
{
    cin >> N;
    vv_graph.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int src, dst, cost;
        cin >> src;
        while (true)
        {
            cin >> dst;
            if (dst == -1)
                break;
            cin >> cost;
            vv_graph[src].push_back(make_pair(cost, dst));
        }
    }
    auto farthest = findFarthest(1);
    auto otherSide = findFarthest(farthest.NODE);
    cout << otherSide.COST << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}