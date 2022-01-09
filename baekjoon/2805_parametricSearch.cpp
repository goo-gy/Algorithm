#include <iostream>
#include <vector>
using namespace std;

long long N, M;
long long hMax = 0;
vector<long long> v_tree;

bool enoughWood(long long height)
{
    long long wood = 0;
    for (auto tree : v_tree)
    {
        long long cut = (tree - height);
        if (cut > 0)
            wood += cut;
    }
    return wood >= M;
}

long long parametric()
{
    long long hStart = 0;
    long long hEnd = hMax;
    while (hStart <= hEnd)
    {
        long long height = (hStart + hEnd) / 2;
        if (enoughWood(height))
            hStart = height + 1;
        else
            hEnd = height - 1;
    }
    return hEnd;
}

int solution()
{
    cin >> N >> M;
    v_tree.resize(N);
    for (auto &tree : v_tree)
    {
        cin >> tree;
        hMax = max(hMax, tree);
    }
    cout << parametric();

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}