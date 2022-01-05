#include <iostream>
#include <vector>

using namespace std;

long long N, M, K;
vector<long long> v_num;
vector<long long> indexTree;
long long leftLeaf, treeSize;

void updateTree(long long index, long long diff)
{
    if (index == 0)
        return;
    indexTree[index] += diff;
    long long parent = index / 2;
    updateTree(parent, diff);
}

void update(long long index, long long data)
{
    long long treeIndex = leftLeaf + index - 1;
    long long diff = data - v_num[index];
    v_num[index] = data;
    updateTree(treeIndex, diff);
}

long long getSum(long long begin, long long end)
{
    long long sum = 0;
    long long L = leftLeaf + begin - 1;
    long long R = leftLeaf + end - 1;

    while (true)
    {
        if (L > R)
            return sum;
        else if (L == R)
            return sum + indexTree[L];

        long long nextL = (L + 1) / 2;
        long long nextR = (R - 1) / 2;

        if (nextL != (L / 2))
            sum += indexTree[L];
        if (nextR != (R / 2))
            sum += indexTree[R];

        L = nextL;
        R = nextR;
    }
}

int solution()
{
    cin >> N >> M >> K;
    v_num.resize(N + 1);

    for (leftLeaf = 1; leftLeaf < N; leftLeaf *= 2);
    treeSize = 2 * leftLeaf;
    indexTree.resize(treeSize);

    for (long long i = 1; i <= N; i++)
    {
        long long data;
        cin >> data;
        update(i, data);
    }

    for (long long i = 1; i <= M + K; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c);
        else if (a == 2)
            cout << getSum(b, c) << "\n";
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