#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
map<int, int> m_tower;

int solution()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int tower;
        cin >> tower;
        auto iterTarget = m_tower.lower_bound(tower);
        if(iterTarget != m_tower.end())
            cout << iterTarget->second << " ";
        else
            cout << 0 << " ";
        
        m_tower[tower] = i;
        auto iterUpdate = m_tower.find(tower);
        m_tower.erase(m_tower.begin(), iterUpdate);
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