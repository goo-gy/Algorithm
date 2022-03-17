#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 30000000
#define NODE first
#define COST second
enum
{
    A,
    B,
    S
};
enum
{
    SRC,
    DST,
    FARE
};
vector<vector<pair<int, int>>> vv_graph;
vector<int> v_distance[3];
vector<int> v_distanceTotal;

void updateDijkstra(int start, int target)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    v_distance[target][start] = 0;
    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        for (auto next : vv_graph[current.NODE])
        {
            int newDistance = v_distance[target][current.NODE] + next.COST;
            if (newDistance < v_distance[target][next.NODE])
            {
                v_distance[target][next.NODE] = newDistance;
                q.push(make_pair(next.NODE, newDistance));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    vv_graph.resize(n + 1);
    v_distance[A].resize(n + 1, INF);
    v_distance[B].resize(n + 1, INF);
    v_distance[S].resize(n + 1, INF);

    for (auto fare : fares)
    {
        vv_graph[fare[SRC]].push_back(make_pair(fare[DST], fare[FARE]));
        vv_graph[fare[DST]].push_back(make_pair(fare[SRC], fare[FARE]));
    }
    updateDijkstra(a, A);
    updateDijkstra(b, B);
    updateDijkstra(s, S);

    int answer = INF;
    for (int i = 1; i <= n; i++)
    {
        int cost = v_distance[A][i] + v_distance[B][i] + v_distance[S][i];
        answer = min(answer, cost);
    }
    return answer;
}