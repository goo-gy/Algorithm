#include <vector>

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
        // TODO : set logic
        return num1 + num2;
    }

    void updateTree(int index)
    {
        if (index == 0)
            return;
        v_tree[index] = logicFun(v_tree[2 * index], v_tree[2 * index + 1]);
        updateTree(index / 2);
    }

    void update(int order, long long data)
    {
        int index = leafLeft + order - 1;
        v_tree[index] = data;
        updateTree(index / 2);
    }

    long long query(int begin, int end)
    {
        int L = leafLeft + begin - 1;
        int R = leafLeft + end - 1;

        // TODO: set initial
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
