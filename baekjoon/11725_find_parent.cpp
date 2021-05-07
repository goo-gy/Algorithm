#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<int> parent_map;
vector<vector<int>> tree_graph;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    queue<int> node_queue;
    node_queue.push(1);

    parent_map[1] = -1;
    while(!node_queue.empty())
    {
        int current = node_queue.front();
        node_queue.pop();
        for(int i = 0; i < tree_graph[current].size(); i++)
        {
            int next = tree_graph[current][i];
            if(0 == parent_map[next])
            {
                parent_map[next] = current;
                node_queue.push(next);
            }
        }
    }
    return 0;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    parent_map.resize(N+1);
    tree_graph.resize(N+1);
    for(int i = 1; i < N; i++)
    {
        int number1, number2;
        cin >> number1 >> number2;
        tree_graph[number1].push_back(number2);
        tree_graph[number2].push_back(number1);
    }
    return 0;
}

int print_output(int result)
{
    for (int i = 2; i <= N; i++)
    {
        cout << parent_map[i] << "\n";
    }
    return 0;
}