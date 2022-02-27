#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class IndexTree
{
public:
    int leafLeft;
    int treeSize;
    vector<long long> v_tree;
    IndexTree(int N)
    {
        for (leafLeft = 1; leafLeft < N; leafLeft *= 2)
            ;
        treeSize = leafLeft * 2;
        v_tree.resize(treeSize);
    }

    long long logicFun(long long num1, long long num2)
    {
        return num1 + num2;
    }

    void updateTree(int index)
    {
        if (index == 0)
            return;
        v_tree[index] = logicFun(v_tree[2 * index], v_tree[2 * index + 1]);
        updateTree(index / 2);
    }

    void add(int order)
    {
        int index = leafLeft + order - 1;
        v_tree[index]++;
        updateTree(index / 2);
    }

    long long query(int begin, int end)
    {
        int L = leafLeft + begin - 1;
        int R = leafLeft + end - 1;

        long long result = 0;
        while (L < R)
        {
            int nextL = (L + 1) / 2;
            int nextR = (R - 1) / 2;

            if (nextL != L / 2)
                result = logicFun(result, v_tree[L]);
            if (nextR != R / 2)
                result = logicFun(result, v_tree[R]);

            L = nextL;
            R = nextR;
        }
        if (L == R)
            result = logicFun(result, v_tree[L]);
        return result;
    }
};

int N;
map<int, int> m_idIndex;

void solution()
{
    priority_queue<pair<int, int>> pq;
    int ident;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> ident;
        m_idIndex[ident] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> ident;
        int index = m_idIndex[ident];
        pq.push(make_pair(index, i));
    }

    IndexTree indexTreeCount(N);
    long long totalCount = 0;
    while (!pq.empty())
    {
        auto machine = pq.top();
        pq.pop();
        long long count = indexTreeCount.query(1, machine.second);
        totalCount += count;
        indexTreeCount.add(machine.second);
    }
    cout << totalCount << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}