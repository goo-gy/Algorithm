#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> graph;
vector<int> colors;

int N, M;

bool BFS(vector<vector<int>> &graph, int start)
{
    queue<pair<int, int>> next_queue; // node, color
    next_queue.push(make_pair(start, 1));
    colors[start] = 1;

    while(!next_queue.empty())
    {
        int current = next_queue.front().first;
        int current_color = next_queue.front().second;
        next_queue.pop();

        for(int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if(colors[next] == -1)
            {
                colors[next] = !current_color;
                next_queue.push(make_pair(next, !current_color));
            } else if(colors[next] == current_color)
                return false;
        }
    }
    return true;
}

int solution()
{
    // input
    cin >> N >> M;
    vector<vector<int>>().swap(graph);
    vector<int>().swap(colors);
    graph.resize(N + 1);
    colors.resize(N + 1, -1);

    // solution
    for(int i = 0; i < M; i++)
    {
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    bool is_bipartite;
    for(int i = 1; i <=  N; i++)
    {
        if(colors[i] == -1)
        {
        is_bipartite = BFS(graph, i);
        if(!is_bipartite)
            break;
        }
    }

    // output
    if(is_bipartite)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    
    return 0;
}

int test_cases()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        solution();
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_cases();
    return 0;
}