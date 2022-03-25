#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string str_input;
string str_convert;
map<char, int> map_level;

void initialize()
{
    map_level['+'] = 1;
    map_level['-'] = 1;
    map_level['*'] = 2;
    map_level['/'] = 2;
}

void preProcess()
{
    vector<int> v_level;
    v_level.push_back(1);
    char openStack = 0;
    int i = 0;
    while (i < str_input.size() - 1)
    {
        char var = str_input[i];
        char op = str_input[i + 1];
        if (var == '(')
        {
            str_convert += var;
            v_level.push_back(1);
            i++;
            continue;
        }
        else if (var == ')')
        {
            str_convert += var;
            v_level.pop_back();
            i++;
            continue;
        }
        if (map_level.find(op) == map_level.end())
        {
            str_convert += var;
            i++;
            continue;
        }

        if (map_level[op] > v_level[v_level.size() - 1])
        {
            str_convert += '(';
            openStack++;
        }
        str_convert += var;
        if (map_level[op] < v_level[v_level.size() - 1])
        {
            str_convert += ')';
            openStack--;
        }
        str_convert += op;
        v_level[v_level.size() - 1] = map_level[op];
        i += 2;
    }
    str_convert += str_input.back();
    for (int i = 1; i <= openStack; i++)
        str_convert += ')';
    cout << str_convert << endl;
}

void process()
{
    vector<vector<string>> vv_var(1);
    vector<char> vv_op;

    for (auto symbol : str_convert)
    {
        if (symbol == '(')
            vv_var.push_back(vector<string>(0));
        else if (symbol == ')')
        {
            string symbolSet = vv_var.back().back();
            vv_var.pop_back();
            vv_var.back().push_back(symbolSet);
        }
        else if (map_level.find(symbol) != map_level.end())
        {
            vv_op.push_back(symbol);
        }
        else
            vv_var.back().push_back(string(1, symbol));

        if (vv_var.back().size() == 2)
        {
            string symbolSet = vv_var.back().front() + vv_var.back().back() + vv_op.back();
            vv_var.back().clear();
            vv_op.pop_back();
            vv_var.back().push_back(symbolSet);
        }
    }

    cout << vv_var.front().front() << "\n";
}

void solution()
{
    cin >> str_input;
    initialize();
    preProcess();
    process();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}