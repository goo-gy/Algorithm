#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v_parent;
vector<long long> v_weight;

void reset()
{
    v_parent.clear();
    v_weight.clear();
}

int find(int node)
{
    if (v_parent[node] == -1)
        return node;
    int root = find(v_parent[node]);
    v_weight[node] += v_weight[v_parent[node]];
    v_parent[node] = root;
    return root;
}

void merge(int node1, int node2, long long diff)
{
    int root1 = find(node1);
    int root2 = find(node2);
    if (root1 == root2)
        return;
    long long diff1 = v_weight[root1] - v_weight[node1];
    long long diff2 = v_weight[root2] - v_weight[node2] + diff;
    if (diff1 < diff2)
    {
        v_parent[root1] = root2;
        v_weight[root1] = diff1 - diff2;
    }
    else
    {
        v_parent[root2] = root1;
        v_weight[root2] = diff2 - diff1;
    }
}

void query(int node1, int node2)
{
    int root1 = find(node1);
    int root2 = find(node2);
    if (root1 == root2)
        cout << v_weight[node2] - v_weight[node1] << "\n";
    else
        cout << "UNKNOWN\n";
}

void solution()
{
    while (true)
    {
        reset();
        cin >> N >> M;
        if (N == 0 && M == 0)
            return;
        v_parent.resize(N + 1, -1);
        v_weight.resize(N + 1);
        for (int i = 1; i <= M; i++)
        {
            char type;
            int a, b, w;
            cin >> type >> a >> b;
            if (type == '!')
            {
                cin >> w;
                merge(a, b, w);
            }
            else if (type == '?')
                query(a, b);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}