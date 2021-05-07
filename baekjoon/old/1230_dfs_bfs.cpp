#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int read_input();
int solution();

int N, E, start;
vector<int> visited;
vector<vector<int>> vertex_edge;

int main()
{
    read_input();
    int result = solution();
    return 0;
}

void initialize()
{
    for(int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }
}

void DFS(int start)
{
    stack<int> stack_next;
    stack_next.push(start);

    while(!stack_next.empty())
    {
        int current = stack_next.top();
        stack_next.pop();

        if(!visited[current])
        {
            cout << current << " ";
            visited[current] = true;
        }

        for(int i = vertex_edge[current].size() - 1; i >= 0; i--)
        {
            int next = vertex_edge[current][i];
            if(!visited[next])
            {
                stack_next.push(next);
            }
        }
    }
}

void BFS(int start)
{
    queue<int> queue_next;
    queue_next.push(start);
    visited[start] = true;

    while(!queue_next.empty())
    {
        int current = queue_next.front();
        queue_next.pop();
        cout << current << " ";

        for(int i = 0; i < vertex_edge[current].size(); i++)
        {
            int next = vertex_edge[current][i];
            if(!visited[next])
            {
                visited[next] = true;
                queue_next.push(next);
            }
        }
    }
}

int solution()
{
    initialize();
    DFS(start);
    cout << endl;
    initialize();
    BFS(start);
    return 0;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E >> start;
    
    visited.resize(N+1);
    vertex_edge.resize(N+1);

    int edge1, edge2;
    for(int i = 0; i < E; i++)
    {
        cin >> edge1 >> edge2;
        
        vertex_edge[edge1].push_back(edge2);
        vertex_edge[edge2].push_back(edge1);
    }
    for(int i = 1; i <= N; i++)
    {
        sort(vertex_edge[i].begin(), vertex_edge[i].end());
    }
    return 0;
}