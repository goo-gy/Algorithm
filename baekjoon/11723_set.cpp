#include <iostream>
#include <vector>
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
vector<int> v_num(21);

int getCmd()
{
    string str_cmd;
    cin >> str_cmd;
    auto iter = find(v_command.begin(), v_command.end(), str_cmd);
    return iter - v_command.begin();
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
            v_num[num] = 1;
            break;
        case REMOVE:
            cin >> num;
            v_num[num] = 0;
            break;
        case CHECK:
            cin >> num;
            cout << v_num[num] << "\n";
            break;
        case TOGGLE:
            cin >> num;
            v_num[num] = !v_num[num];
            break;
        case ALL:
            for (int i = 1; i <= 20; i++)
                v_num[i] = 1;
            break;
        case EMPTY:
            for (int i = 1; i <= 20; i++)
                v_num[i] = 0;
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