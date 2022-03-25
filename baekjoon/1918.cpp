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
    vector<int> v_level(1, 1);
    vector<bool> v_open(1, false);
    vector<vector<string>> vv_symbol(1);
    int i = 0;
    for (auto symbol : str_input)
    {
        if (symbol == '(')
        {
            v_level.push_back(1);
            v_open.push_back(false);
            vv_symbol.push_back(vector<string>(1, string("(")));
        }
        else if (symbol == ')')
        {
            vv_symbol.back().push_back(string(")"));
            if (v_open.back())
                vv_symbol.back().back() = vv_symbol.back().back() + ")";
            string symbolSet = "";
            for (auto symbol : vv_symbol.back())
                symbolSet += symbol;
            v_level.pop_back();
            v_open.pop_back();
            vv_symbol.pop_back();
            vv_symbol.back().push_back(symbolSet);
        }
        else
        {
            auto iterLevel = map_level.find(symbol);
            if (iterLevel != map_level.end())
            {
                if (iterLevel->second > v_level.back())
                {
                    vv_symbol.back().back() = "(" + vv_symbol.back().back();
                    v_open.back() = true;
                }
                else if (iterLevel->second < v_level.back())
                {
                    vv_symbol.back().back() = vv_symbol.back().back() + ")";
                    v_open.back() = false;
                }
                v_level.back() = iterLevel->second;
            }
            vv_symbol.back().push_back(string(1, symbol));
        }
    }
    str_convert = "";
    if (v_open.back())
        vv_symbol.back().back() = vv_symbol.back().back() + ")";
    for (auto symbol : vv_symbol.back())
        str_convert += symbol;
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