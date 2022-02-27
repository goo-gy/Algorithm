#include <iostream>
#include <vector>

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

    void update(int order, int data)
    {
        int index = leafLeft + order - 1;
        v_tree[index] = data;
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

int N, M;
void solution()
{
    cin >> N >> M;
    IndexTree indexTree(N);
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        indexTree.update(i, num);
    }
    for (int i = 1; i <= M; i++)
    {
        int begin, end;
        cin >> begin >> end;
        cout << indexTree.query(begin, end) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}