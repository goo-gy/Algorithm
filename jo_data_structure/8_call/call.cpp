#include <vector>
#include <iostream>
#include <map>
#include <array>

using namespace std;

int N, k1, k2;
map<char, vector<string>> m_function;
array<bool, 256> visited;

int command_count = 0;
bool is_loop = false;
string result1, result2;

void DFS(char start)
{
    if (visited[start])
    {
        is_loop = true;
        return;
    }
    visited[start] = true;
    vector<string> &function = m_function[start];
    for (auto command : function)
    {
        if ('A' <= command[0] && command[0] <= 'Z')
        {
            DFS(command[0]);
        }
        else
        {
            command_count++;
            if (command_count == k1)
            {
                result1 += start;
                result1 += '-';
                result1 += command;
            }
            else if (command_count == k2)
            {
                result2 += start;
                result2 += '-';
                result2 += command;
            }
        }
    }
    visited[start] = false;
}

void solution()
{
    DFS('M');
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    visited.fill(false);
}

void input()
{
    cin >> N >> k1 >> k2;
    for (int i = 1; i <= N; i++)
    {
        char function_name;
        vector<string> v_command;
        string command;
        cin >> function_name;
        while(true)
        {
            cin >> command;
            if(command == "$")
                break;
            v_command.push_back(command);
        }
        m_function.insert(make_pair(function_name, v_command));
    }
}

void output()
{
    if (is_loop)
        cout << "DEADLOCK\n";
    else
    {
        if (result1.size() != 0)
            cout << result1 << "\n";
        else
            cout << "NONE\n";
        if (result2.size() != 0)
            cout << result2 << "\n";
        else
            cout << "NONE\n";
    }
}

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}