#include <iostream>
#include <vector>

#define NONE -1

using namespace std;

int N;
vector<pair<int, int>> v_edge;
vector<int> parent;

int find(int node)
{
    if (parent[node] == NONE)
        return node;
    int root = find(parent[node]);
    parent[node] = root;
    return root;
}

void merge(int node1, int node2)
{
    parent[node1] = node2;
}

int solution()
{
    // input
    cin >> N;
    for (int i = 1; i <= N - 2; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        v_edge.push_back(make_pair(node1, node2));
    }

    // solution
    parent.resize(N + 1, NONE);
    for (auto edge : v_edge)
    {
        int root1 = find(edge.first);
        int root2 = find(edge.second);
        if (root1 != root2)
            merge(root1, root2);
    }

    // output
    for (int node1 = 1; node1 <= N; node1++)
    {
        for (int node2 = node1 + 1; node2 <= N; node2++)
        {
            if (find(node1) != find(node2))
            {
                cout << node1 << " " << node2 << "\n";
                return 0;
            }
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