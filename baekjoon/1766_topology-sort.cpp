#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> vv_graph;
vector<int> v_degree;

void solution()
{
    priority_queue<int, vector<int>, greater<int>> pq_node;
    for (int i = 1; i <= N; i++)
    {
        if(v_degree[i] == 0)
            pq_node.push(i);
    }

    while(!pq_node.empty())
    {
        int cur = pq_node.top(); pq_node.pop();
        cout << cur << " ";
        for(int dst : vv_graph[cur])
        {
            v_degree[dst]--;
            if(v_degree[dst] == 0)
                pq_node.push(dst);
        }
    }
    cout << "\n";
}

void input()
{
    cin >> N >> M;
    vv_graph.resize(N + 1);
    v_degree.resize(N + 1);
    for (int i = 1; i <= M; i++)
    {
        int src, dst;
        cin >> src >> dst;
        vv_graph[src].push_back(dst);
        v_degree[dst]++;
    }
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    pre_setting();
    input();
    solution();
    return 0;
}