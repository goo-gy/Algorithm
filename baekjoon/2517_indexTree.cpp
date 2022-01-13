#include <iostream>
#include <vector>
#include <queue>

#define SPEED first
#define ORDER second

using namespace std;

class IndexTree
{
public:
    int leafLeft;
    int treeSize;
    vector<int> v_tree;
    IndexTree(int N)
    {
        for (leafLeft = 1; leafLeft < N; leafLeft *= 2)
            ;
        treeSize = leafLeft * 2;
        v_tree.resize(treeSize);
    }

    int logicFun(int num1, int num2)
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

    int query(int begin, int end)
    {
        int L = leafLeft + begin - 1;
        int R = leafLeft + end - 1;

        int result = 0;
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
vector<int> v_speed;
priority_queue<pair<int, int>> pq_runner;
vector<int> v_rank;

void solution()
{
    cin >> N;
    v_speed.resize(N + 1);
    v_rank.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int speed;
        cin >> speed;
        pq_runner.push(make_pair(speed, i));
    }

    IndexTree indexTreeCount(N);
    while (!pq_runner.empty())
    {
        auto runner = pq_runner.top();
        pq_runner.pop();
        v_rank[runner.ORDER] = indexTreeCount.query(1, runner.ORDER) + 1;
        indexTreeCount.add(runner.ORDER);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << v_rank[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}