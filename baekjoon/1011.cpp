#include <iostream>
#include <vector>
using namespace std;

long long N;

int solution()
{
    // input
    int x, y;
    cin >> x >> y;
    N = y - x;

    // solution
    int result;
    if (N == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    if (N == 2)
    {
        cout << 2 << "\n";
        return 0;
    }

    long long index = 3;
    int count = 1;
    int container = 2;

    while (true)
    {
        for (int k = 1; k <= 2; k++)
        {
            if (index <= N && N < index + container)
            {
                cout << count + 2 << "\n";
                return 0;
            } 
            index += container;
            count++;
        }
        container++;
    }

    return 0;
}

int test_case()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solution();
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_case();
    return 0;
}
