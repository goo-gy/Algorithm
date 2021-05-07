#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<bool> infected;
vector<vector<int>> network_graph;


int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    queue<int> next_queue;
    next_queue.push(1);
    infected[1] = true;

    int infect_count = 0;
    while(!next_queue.empty())
    {
        int current = next_queue.front();
        next_queue.pop();
        for (int i = 0; i < network_graph[current].size(); i++)
        {
            int next = network_graph[current][i];
            if(infected[next] == false)
            {
                infected[next] = true;
                next_queue.push(next);
                infect_count++;
            }
        }
    }
    return infect_count;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int edge_count;
    cin >> N >> edge_count;
    infected.resize(N+2, false);
    network_graph.resize(N+2);

    int node1, node2;
    for (int i = 0; i < edge_count; i++)
    {
        cin >> node1 >> node2;
        network_graph[node1].push_back(node2);
        network_graph[node2].push_back(node1);
    }
    
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}