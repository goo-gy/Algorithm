#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
map<string, string> m_parent;
map<string, int> m_size;

void pre_setting();
void input();
void output();

int main()
{
    pre_setting();
    input();
    output();
    return 0;
}

int get_level(string member, int depth)
{
    auto iter_parent = m_parent.find(member);
    if(iter_parent == m_parent.end())
        return depth;
    return get_level(iter_parent->second, depth + 1);
}

bool cmp(const pair<string, int> &A, const pair<string, int> &B)
{
    if(A.second == B.second)
    {
        int levelA = get_level(A.first, 0);
        int levelB = get_level(B.first, 0);
        if(levelA == levelB)
            return A.first < B.first;
        return levelA < levelB;
    }
    return A.second > B.second;
}

void update_size(string boss, int size)
{
    auto iter_size = m_size.find(boss);
    if(iter_size != m_size.end())
        iter_size->second = iter_size->second + size;
    else 
        m_size[boss] = size;
    
    auto iter_parent = m_parent.find(boss);
    if(iter_parent != m_parent.end())
        update_size(iter_parent->second, size);
}


void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        string member, boss;
        cin >> member >> boss;
        m_parent[member] = boss;
        
        auto iter_size = m_size.find(member);
        if(iter_size == m_size.end())
            m_size[member] = 0;
        update_size(boss, m_size[member] + 1);
    }
}

void output()
{
    vector<pair<string,int>> v_size_mem(m_size.begin(), m_size.end());
    sort(v_size_mem.begin(), v_size_mem.end(), cmp);
    for(auto member : v_size_mem)
    {
        cout << member.first << endl;
    }
}