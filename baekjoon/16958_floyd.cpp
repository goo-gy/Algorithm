#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define S 0
#define X 1
#define Y 2

int N, T;
int M;
vector<tuple<int, int, int>> cities;
vector<vector<int>> graph;
vector<pair<int, int>> targets;


void floyd_warshall()
{
    for(int middle = 1; middle <= N; middle++)
    {
        for(int src = 1; src <= N; src++)
        {
            for(int dst = 1; dst <= N; dst++)
            {
                if(src == dst)
                    continue;
                graph[src][dst] = min(graph[src][middle] + graph[middle][dst], graph[src][dst]);
            }
        }
    }
}


int solution()
{
    // input
    cin >> N >> T;
    cities.resize(N + 1);
    graph.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int special, x, y;
        cin >> special >> x >> y;
        cities[i] = make_tuple(special, x, y);
        graph[i].resize(N + 1);
    }
    cin >> M;
    targets.resize(M);
    for (int i = 0; i < M; i++)
    {
        int src, dst;
        cin >> src >> dst;
        targets[i] = make_pair(src, dst);
    }

    // solution
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int distance = abs(get<X>(cities[i]) - get<X>(cities[j])) + abs(get<Y>(cities[i]) - get<Y>(cities[j]));
            if(get<S>(cities[i]) && get<S>(cities[j]) && distance > T)
            {
                distance = T;
            }
            graph[i][j] = distance;
            graph[j][i] = distance;
        }
    }
    floyd_warshall();

    // output
    for (int i = 0; i < M; i++)
    {
        cout << graph[targets[i].first][targets[i].second] << "\n";
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