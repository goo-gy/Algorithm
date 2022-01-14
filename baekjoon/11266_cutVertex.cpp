#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define INF 1234567890

int V, E;
vector<vector<int>> graph;
vector<int> v_order;
vector<bool> v_visit;
set<int> set_cutVertex;

int DFS(int current, int order)
{
    v_visit[current] = true;
    v_order[current] = order;
    int fastParent = current;
    for (auto next : graph[current])
    {
        if (v_order[next] < v_order[fastParent])
            fastParent = next;
        if (!v_visit[next])
        {
            int result = DFS(next, order + 1);
            if (result == current)
                set_cutVertex.insert(current);
            if (v_order[result] < v_order[fastParent])
                fastParent = result;
        }
    }
    return fastParent;
}

void findCutVertex()
{
    for (int i = 1; i <= V; i++)
    {
        if (v_visit[i])
            continue;
        int root = i;
        int order = 1;
        v_visit[root] = true;
        v_order[root] = order;

        int visitCount = 0;
        for (auto next : graph[root])
        {
            if (!v_visit[next])
            {
                visitCount++;
                int result = DFS(next, order + 1);
            }
        }
        if (visitCount >= 2)
            set_cutVertex.insert(root);
    }
}

void solution()
{
    cin >> V >> E;
    graph.resize(V + 1);
    v_order.resize(V + 1, INF);
    v_visit.resize(V + 1, false);
    for (int i = 1; i <= E; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    findCutVertex();
    cout << set_cutVertex.size() << "\n";
    for (auto cutVertex : set_cutVertex)
        cout << cutVertex << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}