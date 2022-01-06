#include <iostream>
#include <vector>
using namespace std;

long long N, Q;

class IndexTree
{
    vector<long long> v_tree;
    long long firstLeaf;
    long long treeSize;

public:
    IndexTree(long long range)
    {
        for (firstLeaf = 1; firstLeaf < range; firstLeaf *= 2);
        treeSize = firstLeaf * 2;
        v_tree.resize(treeSize);
    }

    void updateTree(long long index)
    {
        if (index == 0)
            return;
        v_tree[index] = v_tree[index * 2] + v_tree[index * 2 + 1];
        updateTree(index / 2);
    }

    void update(long long number, long long data)
    {
        int index = number + firstLeaf - 1;
        v_tree[index] = data;
        updateTree(index / 2);
    }

    long long getSum(long long number1, long long number2)
    {
        long long sum = 0;
        long long begin = number1 + firstLeaf - 1;
        long long end = number2 + firstLeaf - 1;

        while (true)
        {
            if (begin > end)
                return sum;
            else if (begin == end)
                return sum + v_tree[begin];

            long long nextBegin = (begin + 1) / 2;
            long long nextEnd = (end - 1) / 2;

            if (nextBegin != (begin / 2))
                sum += v_tree[begin];
            if (nextEnd != (end / 2))
                sum += v_tree[end];

            begin = nextBegin;
            end = nextEnd;
        }
    }
};

int solution()
{
    // input
    cin >> N >> Q;
    IndexTree indexTree(N);

    for (long long i = 1; i <= N; i++)
    {
        long long num;
        cin >> num;
        indexTree.update(i, num);
    }
    for (long long i = 1; i <= Q; i++)
    {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << indexTree.getSum(min(x, y), max(x, y)) << "\n";
        indexTree.update(a, b);
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