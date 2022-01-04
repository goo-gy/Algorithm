#include <iostream>
#include <set>

using namespace std;

int N, M;
set<int> A;

int solution()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        A.insert(num);
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        int num;
        cin >> num;
        auto iter = A.find(num);
        if (iter != A.end())
            cout << "1\n";
        else
            cout << "0\n";
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