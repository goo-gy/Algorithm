#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, W;
vector<int> v_build_time;
vector<int> v_enter_degree;
vector<int> v_enter_wait;
vector<vector<int>> vv_graph;

int topology_sort()
{
    queue<int> node_queue;
    for (int i = 1; i <= N; i++)
    {
        if(!v_enter_degree[i])
            node_queue.push(i);
    }
    
    while (!node_queue.empty())
    {
        int current = node_queue.front();
        node_queue.pop();

        if(current == W)
            return v_enter_wait[current] + v_build_time[current];
        
        for (int i = 0; i < vv_graph[current].size(); i++)
        {
            int next = vv_graph[current][i];
            v_enter_degree[next]--;
            v_enter_wait[next] = max(v_enter_wait[next], v_enter_wait[current] + v_build_time[current]);
            if (!v_enter_degree[next])
                node_queue.push(next);
        }
    }
}

int solution()
{
    // input
    cin >> N >> K;
    v_build_time.resize(N + 1);
    v_enter_degree.resize(N + 1);
    v_enter_wait.resize(N + 1, 0);
    vv_graph.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> v_build_time[i];
    }
    for (int i = 0; i < K; i++)
    {
        int src, dst;
        cin >> src >> dst;
        vv_graph[src].push_back(dst);
        v_enter_degree[dst]++;
    }
    cin >> W;

    // solution
    int result = topology_sort();

    // output
    cout << result << "\n";

    return 0;
}

void clear()
{
    v_build_time.resize(0);
    v_enter_degree.resize(0);
    v_enter_wait.resize(0);
    vv_graph.resize(0);
}

void test_case()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solution();
        clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_case();
    return 0;
}