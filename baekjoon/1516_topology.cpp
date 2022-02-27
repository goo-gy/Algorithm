#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> graph;
vector<int> v_time;
vector<int> v_timeTotal;
vector<int> v_degree;

void topology()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if(v_degree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        v_timeTotal[current] += v_time[current];
        for(int next : graph[current])
        {
            v_timeTotal[next] = max(v_timeTotal[next], v_timeTotal[current]);
            v_degree[next]--;
            if(v_degree[next] == 0)
                q.push(next);
        }
    }
}

int solution()
{
    cin >> N;
    graph.resize(N + 1);
    v_time.resize(N + 1);
    v_timeTotal.resize(N + 1, 0);
    v_degree.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> v_time[i];
        while(true)
        {
            int src;
            cin >> src;
            if(src == -1)
                break;
            graph[src].push_back(i);
            v_degree[i]++;
        }
    }

    topology();
    for (int i = 1; i <= N; i++)
    {
        cout << v_timeTotal[i] << "\n";
    }
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}