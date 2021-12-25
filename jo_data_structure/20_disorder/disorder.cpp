#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

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
    if (cmdInput.size() != 1)
        return ERROR;

    auto iter = find(v_command.begin(), v_command.end(), cmdInput);
    if (iter == v_command.end())
        return ERROR;

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
        vector<int> v_disease;
        for(auto iter = m_geneDisease.lower_bound(s_gene); iter != m_geneDisease.upper_bound(s_gene); iter++)
            v_disease.push_back(iter->second);
        sort(v_disease.begin(), v_disease.end(), greater<int>());
        for(auto disease : v_disease)
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
            return;
        }
    }
}

int main()
{
    solution();
    return 0;
}