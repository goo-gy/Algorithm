#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define INF 1234567890
#define PC first
#define COST second

int N, M;
vector<vector<pair<int, int>>> vv_graph;
vector<int> v_distance;
vector<int> v_visitedFrom;
set<pair<int, int>> s_route;

class Point
{
public:
    int pc;
    int from;
    int distance;
    Point(int _pc, int _from, int _distance) : pc(_pc), from(_from), distance(_distance)
    {
    }
    bool operator<(const Point &other) const
    {
        return this->distance < other.distance;
    }
};

void initialize()
{
    vv_graph.resize(N + 1);
    v_distance.resize(N + 1, INF);
    v_visitedFrom.resize(N + 1, 0);
}

void dijkstra()
{
    priority_queue<Point> q;
    q.push(Point(1, 1, 0));
    v_visitedFrom[1] = 1;
    v_distance[1] = 0;

    while (!q.empty())
    {
        Point current = q.top();
        q.pop();

        if (current.pc != 1)
            s_route.insert(make_pair(min(current.pc, v_visitedFrom[current.pc]), max(current.pc, v_visitedFrom[current.pc])));

        for (auto next : vv_graph[current.pc])
        {
            if (v_distance[current.pc] + next.COST < v_distance[next.PC])
            {
                v_visitedFrom[next.PC] = current.pc;
                v_distance[next.PC] = v_distance[current.pc] + next.COST;
                q.push(Point(next.PC, current.pc, -v_distance[next.PC]));
            }
        }
    }
}

void solution()
{
    cin >> N >> M;
    initialize();
    for (int i = 1; i <= M; i++)
    {
        int pc1, pc2, cost;
        cin >> pc1 >> pc2 >> cost;
        vv_graph[pc1].push_back(make_pair(pc2, cost));
        vv_graph[pc2].push_back(make_pair(pc1, cost));
    }
    dijkstra();
    cout << s_route.size() << "\n";
    for (auto edge : s_route)
        cout << edge.first << " " << edge.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}