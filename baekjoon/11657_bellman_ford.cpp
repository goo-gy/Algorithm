#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

#define INF 1234567890

int N, M;
map<pair<int,int>, long long> loads;
vector<long long> distance_map;

bool bellman_ford()
{
    distance_map[1] = 0;
    for(int n = 1; n <= N; n++)
    {
        for(map<pair<int,int>, long long>::iterator e = loads.begin(); e != loads.end(); e++)
        {
            int src = e->first.first;
            int dst = e->first.second;
            long long weight = e->second;
            if(distance_map[src] != INF && distance_map[dst] > distance_map[src] + weight)
            {
                distance_map[dst] = distance_map[src] + weight;
                if(n == N)
                    return true;
            }
        }
    }
    return false;
}

int solution()
{
    // input
    cin >> N >> M;;
    distance_map.resize(N+1, INF);
    for(int i = 0; i < M; i++)
    {
        int src, dst, weight;
        cin >> src >> dst >> weight;
        map<pair<int,int>, long long>::iterator iter = loads.find(make_pair(src, dst));
        if(iter == loads.end() || weight < loads[make_pair(src, dst)])
            loads[make_pair(src, dst)] = weight;
    }

    // solution
    bool have_minus_cycle = bellman_ford();

    // output
    if(have_minus_cycle)
        cout << -1 << "\n";
    else
    {
        for(int n = 2; n <= N; n++)
        {
            if(distance_map[n] == INF)
                cout << -1 << "\n";
            else
                cout << distance_map[n] << "\n";
        }
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