#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int N;

int getOrder(int n, int r, int c)
{
    if (n == 0)
        return 0;
    int halfLen = 1 << (n - 1);
    int quadSize = halfLen * halfLen;

    if (r < halfLen && c < halfLen)
        return getOrder(n - 1, r, c);
    else if (r < halfLen && c >= halfLen)
        return quadSize + getOrder(n - 1, r, c - halfLen);
    else if (r >= halfLen && c < halfLen)
        return 2 * quadSize + getOrder(n - 1, r - halfLen, c);
    else if (r >= halfLen && c >= halfLen)
        return 3 * quadSize + getOrder(n - 1, r - halfLen, c - halfLen);
    else
        assert(false);
}

void solution()
{
    int r, c;
    cin >> N >> r >> c;
    int result = getOrder(N, r, c);
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}