#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
enum
{
    ADD,
    REMOVE,
    CHECK,
    TOGGLE,
    ALL,
    EMPTY
};
vector<string> v_command = {
    "add",
    "remove",
    "check",
    "toggle",
    "all",
    "empty"};
set<int> set_num;

int getCmd()
{
    string str_cmd;
    cin >> str_cmd;
    auto iter = find(v_command.begin(), v_command.end(), str_cmd);
    return iter - v_command.begin();
}

void remove()
{
    int num;
    cin >> num;
    auto iter = set_num.find(num);
    if (iter != set_num.end())
        set_num.erase(iter);
}

void check()
{
    int num;
    cin >> num;
    auto iter = set_num.find(num);
    if (iter != set_num.end())
        cout << "1\n";
    else
        cout << "0\n";
}

void toggle()
{
    int num;
    cin >> num;
    auto iter = set_num.find(num);
    if (iter != set_num.end())
        set_num.erase(iter);
    else
        set_num.insert(num);
}

void solution()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int cmd = getCmd();
        int num;
        switch (cmd)
        {
        case ADD:
            cin >> num;
            set_num.insert(num);
            break;
        case REMOVE:
            remove();
            break;
        case CHECK:
            check();
            break;
        case TOGGLE:
            toggle();
            break;
        case ALL:
            for (int i = 1; i <= 20; i++)
                set_num.insert(i);
            break;
        case EMPTY:
            set_num.clear();
            break;
        default:
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}