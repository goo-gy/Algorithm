#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> vv_graph;
vector<int> v_degree;

int solution()
{
    // input
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

    // solution
    queue<int> q_node;
    for (int i = 1; i <= N; i++)
    {
        if(v_degree[i] == 0)
            q_node.push(i);
    }

    while(!q_node.empty())
    {
        int cur = q_node.front();  q_node.pop();
        cout << cur << " ";
        for(int dst : vv_graph[cur])
        {
            v_degree[dst]--;
            if(v_degree[dst] == 0)
                q_node.push(dst);
        }
    }
    cout << "\n";
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}