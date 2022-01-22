#include <iostream>
#include <vector>

using namespace std;

int N, M;
int sizeExp;
vector<vector<int>> vv_graph;
vector<vector<int>> vv_tree;
vector<bool> v_visit;
vector<int> v_depth;

void reset()
{
    for (sizeExp = 1; (1 << sizeExp) <= N; sizeExp++)
        ;
    v_visit.resize(N + 1, false);
    v_depth.resize(N + 1);
    vv_graph.resize(N + 1);
    vv_tree.resize(N + 1);
    for (int i = 0; i <= N; i++)
        vv_tree[i].resize(sizeExp, 0);
}

void setAncestor(int node)
{
    for (int k = 1; k < sizeExp; k++)
    {
        int kAncestor = vv_tree[node][k - 1];
        vv_tree[node][k] = vv_tree[kAncestor][k - 1];
    }
}

void makeTreeDFS(int current, int depth)
{
    v_visit[current] = true;
    v_depth[current] = depth;
    for (auto next : vv_graph[current])
    {
        if (!v_visit[next])
        {
            vv_tree[next][0] = current;
            setAncestor(next);
            v_visit[next] = true;
            makeTreeDFS(next, depth + 1);
        }
    }
}

int findLCA(int node1, int node2)
{
    int low = v_depth[node1] > v_depth[node2] ? node1 : node2;
    int high = v_depth[node1] > v_depth[node2] ? node2 : node1;
    int depthDiff = v_depth[low] - v_depth[high];
    while (depthDiff > 0)
    {
        int expIndex;
        for (expIndex = 0; (1 << expIndex) <= depthDiff; expIndex++)
            ;
        expIndex--;
        low = vv_tree[low][expIndex];
        depthDiff = v_depth[low] - v_depth[high];
    }

    int k = sizeExp - 1;
    while (k >= 0)
    {
        int lowAn = vv_tree[low][k];
        int highAn = vv_tree[high][k];
        if (lowAn != highAn)
        {
            low = lowAn;
            high = highAn;
        }
        k--;
    }
    if (low == high)
        return low;
    else
        return vv_tree[low][0];
}
void solution()
{
    cin >> N;
    reset();
    for (int i = 1; i <= N - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        vv_graph[node1].push_back(node2);
        vv_graph[node2].push_back(node1);
    }
    makeTreeDFS(1, 0);
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        cout << findLCA(node1, node2) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}