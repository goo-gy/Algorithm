#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define WEIGHT 0
#define SRC 1
#define DST 2

using namespace std;

int N, M;
vector<tuple<int, int, int>> v_edge;
vector<int> v_parent;

void merge(int root1, int root2)
{
    v_parent[root1] = root2;
}

int findRoot(int node)
{
    if(v_parent[node] == -1)
        return node;
    else {
        v_parent[node] = findRoot(v_parent[node]);
        return v_parent[node];
    }
}

int kruskal()
{
    sort(v_edge.begin(), v_edge.end());
    v_parent.resize(N + 1, -1);

    int count = 0;
    int weightSum = 0;

    for(auto edge : v_edge)
    {
        int root1 = findRoot(get<SRC>(edge));
        int root2 = findRoot(get<DST>(edge));
        if(root1 != root2)
        {
            merge(root1, root2);
            count++;
            weightSum += get<WEIGHT>(edge);
            if(count == N - 2)
                break;
        }
    }
    return weightSum;
}

int solution()
{
    // input
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int src, dst, weight;
        cin >> src >> dst >> weight;
        v_edge.push_back(make_tuple(weight, src, dst));
    }
    
    // solution
    int result = kruskal();

    // output
    cout << result << "\n";
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}