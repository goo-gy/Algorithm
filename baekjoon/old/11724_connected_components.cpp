#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int read_input();
int print_output(int result);
int solution();
int N, M;

vector<bool> visited;
vector<vector<int>> graph;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

struct Point
{
    int row, col;
};

int BFS(int start)
{
    if(visited[start])
        return 0;

    queue<int> node_queue;
    node_queue.push(start);
    
    visited[start] = true;

    while(!node_queue.empty())
    {
        int current = node_queue.front();
        node_queue.pop();
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if(!visited[next])
            {
                node_queue.push(next);
                visited[next] = true;
            }
        }
    }
    return 1;
}

int solution()
{
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        count += BFS(i);
    }
    return count;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    visited.resize(N + 1, false);
    graph.resize(N + 1);

    int first, second;
    for(int i = 0; i < M; i++)
    {
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}