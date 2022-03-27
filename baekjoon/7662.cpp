#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
multiset<int> numSet;

void popNum(int num)
{
    if (numSet.empty())
        return;

    if (num == 1)
    {
        auto iter = numSet.end();
        iter--;
        numSet.erase(iter);
    }
    else if (num == -1)
    {
        auto iter = numSet.begin();
        numSet.erase(iter);
    }
}

void solution()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        char cmd;
        int num;
        cin >> cmd >> num;
        switch (cmd)
        {
        case 'I':
            numSet.insert(num);
            break;
        case 'D':
            popNum(num);
            break;
        default:
            break;
        }
    }
    if (numSet.empty())
        cout << "EMPTY\n";
    else
        cout << *numSet.rbegin() << " " << *numSet.begin() << "\n";
    numSet.clear();
}

void test_case()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_case();
    return 0;
}