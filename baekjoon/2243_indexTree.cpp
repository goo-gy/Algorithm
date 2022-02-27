#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define TASTE_MAX 1000000

long long N;

class CandyTree
{
    long long firstLeaf;
    long long treeSize;
    vector<long long> indexTree;

public:
    CandyTree(long long range)
    {
        for (firstLeaf = 1; firstLeaf < range; firstLeaf *= 2)
            ;
        treeSize = firstLeaf * 2;
        indexTree.resize(treeSize);
    }

    void updateTree(long long index, long long count)
    {
        if (index == 0)
            return;
        indexTree[index] += count;
        updateTree(index / 2, count);
    }

    void pushCandy(long long index, long long count)
    {
        long long treeIndex = index + firstLeaf - 1;
        updateTree(treeIndex, count);
    }

    void findPop(long long rank, long long current)
    {
        if (rank > indexTree[current])
            return;
        indexTree[current]--;
        if (current >= firstLeaf)
        {
            cout << current - firstLeaf + 1 << "\n";
            return;
        }

        long long left = current * 2;
        long long right = current * 2 + 1;
        if (rank <= indexTree[left])
            findPop(rank, left);
        else
            findPop(rank - indexTree[left], right);
    }

    void popCandy(long long rank)
    {
        findPop(rank, 1);
    }
};

int solution()
{
    CandyTree candyTree = CandyTree(TASTE_MAX);
    cin >> N;
    for (long long i = 1; i <= N; i++)
    {
        long long A, B, C;
        cin >> A >> B;
        if (A == 1)
            candyTree.popCandy(B);
        else if (A == 2)
        {
            cin >> C;
            candyTree.pushCandy(B, C);
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