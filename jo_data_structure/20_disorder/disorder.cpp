#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

enum
{
    ERROR = -1,
    REPORT = 0,
    QUERY,
    QUIT
};
vector<string> v_command = {"R", "Q", "$"};
int getCommand()
{
    string cmdInput;
    cin >> cmdInput;
    assert(cmdInput.size() == 1);

    auto iter = find(v_command.begin(), v_command.end(), cmdInput);
    assert(iter != v_command.end());

    int index = iter - v_command.begin();
    return index;
}

int N;
multimap<set<int>, int> m_geneDisease;

void report()
{
    set<int> s_gene;
    while (true)
    {
        int input;
        cin >> input;
        if (input >= 0)
            s_gene.insert(input);
        else
        {
            m_geneDisease.insert(make_pair(s_gene, input));
            return;
        }
    }
}

void printResult(set<int> &s_gene)
{
    auto check = m_geneDisease.find(s_gene);
    if (check != m_geneDisease.end())
    {
        set<int, greater<int>> s_disease;
        auto equal_range = m_geneDisease.equal_range(s_gene);
        for(auto iter = equal_range.first; iter != equal_range.second; iter++)
            s_disease.insert(iter->second);
        for(auto disease : s_disease)
            cout << disease << " ";
    }
    else
        cout << "None";
    cout << endl;
}

void query()
{
    set<int> s_gene;
    while (true)
    {
        int input;
        cin >> input;
        if (input != 0)
            s_gene.insert(input);
        else
        {
            printResult(s_gene);
            return;
        }
    }
}

void solution()
{
    while (true)
    {
        int cmd = getCommand();
        switch (cmd)
        {
        case REPORT:
            report();
            break;
        case QUERY:
            query();
            break;
        case QUIT:
            return;
        default:
            assert(true);
            return;
        }
    }
}

int main()
{
    solution();
    return 0;
}