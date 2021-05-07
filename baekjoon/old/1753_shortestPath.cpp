#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

struct Edge {
    int node;
    int weight;
};

int read_input();
int print_output(int result);
int solution();
int V, E;
int start_node;
vector<vector<Edge>> map;
vector<int> distance_map;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    distance_map[start_node] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> next_queue;

    // distance, weight
    next_queue.push(make_pair(0, start_node));
    while(!next_queue.empty())
    {
        pair<int, int> current = next_queue.top();
        next_queue.pop();
        for(int i = 0; i < map[current.second].size(); i++)
        {
            int new_weight = distance_map[current.second] + map[current.second][i].weight;
            pair<int, int> next = make_pair(new_weight, map[current.second][i].node);
            if(new_weight < distance_map[next.second])
            {
                distance_map[next.second] = new_weight;
                next_queue.push(next);
            }
        }
    }

    return 0;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    cin >> start_node;
    map.resize(V+1);
    distance_map.resize(V+1, INF);

    for(int i = 0; i < E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        map[u].push_back({v,w});
    }
    return 0;
}

int print_output(int result)
{
    for(int i = 1; i <= V; i++)
    {
        if(distance_map[i] == INF)
            cout << "INF" << "\n";
        else
            cout << distance_map[i] << "\n";
    }
    return 0;
}