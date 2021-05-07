#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int read_input();
int print_output(long long result);
long long solution();
int N;
vector<vector<pair<int,int>>> graph;
vector<int> distances;

int main()
{
    read_input();
    long long result = solution();
    print_output(result);
    return 0;
}

int BFS(int start)
{
    memset(&distances[0], -1, distances.size() * sizeof(int));
    queue<int> node_queue;
    node_queue.push(start);
    
    distances[start] = 0;
    while(!node_queue.empty())
    {
        int current = node_queue.front();
        node_queue.pop();
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int weight = graph[current][i].second;
            if(-1 == distances[next])
            {
                distances[next] = distances[current] + weight;
                node_queue.push(next);
            }
        }
    }
    int farthest_node = 0;
    for (int i = 1; i <= N; i++)
    {
        if(distances[farthest_node] < distances[i])
            farthest_node = i;
    }
    return farthest_node;
}

long long solution()
{
    int start = BFS(1);
    int end = BFS(start);
    return distances[end];
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    graph.resize(N+1);
    distances.resize(N+1);
    for(int i = 1; i < N; i++)
    {
        int src, dst, weight;
        cin >> src >> dst >> weight;
        graph[src].push_back(make_pair(dst, weight));
        graph[dst].push_back(make_pair(src, weight));
    }
    return 0;
}

int print_output(long long result)
{
    cout << result << "\n";
    return 0;
}