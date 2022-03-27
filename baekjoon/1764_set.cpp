#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
set<string> m_people;

void solution()
{
    cin >> N >> M;
    string name;
    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        m_people.insert(name);
    }
    vector<string> v_noSeenNoHeard;
    for (int i = 1; i <= M; i++)
    {
        cin >> name;
        auto iter = m_people.find(name);
        if (iter != m_people.end())
            v_noSeenNoHeard.push_back(name);
    }
    sort(v_noSeenNoHeard.begin(), v_noSeenNoHeard.end());
    cout << v_noSeenNoHeard.size() << "\n";
    for (string name : v_noSeenNoHeard)
        cout << name << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}