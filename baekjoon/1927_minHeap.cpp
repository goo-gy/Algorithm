#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

void solution()
{
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
        else
            pq.push(num);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}