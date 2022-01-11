#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v_parent;
vector<tuple<int, int, int>> v_edge;

int find(int node)
{
    if (v_parent[node] == -1)
        return node;
    v_parent[node] = find(v_parent[node]);
    return v_parent[node];
}

bool merge(int node1, int node2)
{
    int root1 = find(node1);
    int root2 = find(node2);
    if(root1 != root2)
    {
        v_parent[root2] = root1;
        return true;
    }
    return false;
}

int solution()
{
    cin >> N >> M;
    v_parent.resize(N + 1, -1);

    int weightSum = 0;
    for (int i = 1; i <= M; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        v_edge.push_back(make_tuple(weight, node1, node2));
    }
    
    sort(v_edge.begin(), v_edge.end());
    for (auto edge : v_edge)
    {
        if(merge(get<1>(edge), get<2>(edge)))
            weightSum += get<0>(edge);
    }
    
    cout << weightSum << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}