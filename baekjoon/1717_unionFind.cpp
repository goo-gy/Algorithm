#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v_parent;

int find(int node)
{
    if (v_parent[node] == -1)
        return node;
    v_parent[node] = find(v_parent[node]);
    return v_parent[node];
}

void merge(int node1, int node2)
{
    int root1 = find(node1);
    int root2 = find(node2);
    if(root1 != root2)
        v_parent[root2] = root1;
}

int solution()
{
    cin >> N >> M;
    v_parent.resize(N + 1, -1);

    for (int i = 1; i <= M; i++)
    {
        int cmd;
        int node1, node2;
        cin >> cmd >> node1 >> node2;

        if (cmd == 0)
            merge(node1, node2);
        else if (cmd == 1)
            cout << (find(node1) == find(node2) ? "YES" : "NO") << "\n";
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