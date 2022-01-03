#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

#define NUM_MAX 1000000000

enum COMMAND
{
    NONE = -1,
    NUM = 0,
    POP,
    INV,
    DUP,
    SWP,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    END,
    QUIT
};

enum RESULT
{
    ERROR = -1,
    OK
};

vector<string> v_commandStr = {"NUM", "POP", "INV", "DUP", "SWP", "ADD", "SUB", "MUL", "DIV", "MOD", "END", "QUIT"};

stack<int> stack_num;
vector<int> v_command;
vector<int> v_num;
int numIndex = 0;

int getCommand()
{
    string cmdStr;
    cin >> cmdStr;

    auto iter = find(v_commandStr.begin(), v_commandStr.end(), cmdStr);
    if (iter != v_commandStr.end())
        return iter - v_commandStr.begin();
    else
        return NONE;
}

int funcNUM()
{
    stack_num.push(v_num[numIndex]);
    numIndex++;
    return OK;
}

int funcPOP()
{
    if (stack_num.empty())
        return ERROR;
    stack_num.pop();
    return OK;
}

int funcINV()
{
    if (stack_num.empty())
        return ERROR;
    int num1 = stack_num.top();
    stack_num.pop();
    stack_num.push(-num1);
    return OK;
}

int funcDUP()
{
    if (stack_num.empty())
        return ERROR;
    int num1 = stack_num.top();
    stack_num.push(num1);
    return OK;
}

int funcSWP()
{
    if (stack_num.size() < 2)
        return ERROR;
    int num1 = stack_num.top();
    stack_num.pop();
    int num2 = stack_num.top();
    stack_num.pop();
    stack_num.push(num1);
    stack_num.push(num2);
    return OK;
}

int funcADD()
{
    if (stack_num.size() < 2)
        return ERROR;
    int num1 = stack_num.top();
    stack_num.pop();
    int num2 = stack_num.top();
    stack_num.pop();

    int result = num1 + num2;
    if (abs(result) > NUM_MAX)
        return ERROR;
    stack_num.push(result);
    return OK;
}

int funcSUB()
{
    if (stack_num.size() < 2)
        return ERROR;
    int num1 = stack_num.top();
    stack_num.pop();
    int num2 = stack_num.top();
    stack_num.pop();

    int result = num2 - num1;
    if (abs(result) > NUM_MAX)
        return ERROR;
    stack_num.push(result);
    return OK;
}

int funcMUL()
{
    if (stack_num.size() < 2)
        return ERROR;
    int num1 = stack_num.top();
    stack_num.pop();
    int num2 = stack_num.top();
    stack_num.pop();

    if (num1 == 0)
    {
        stack_num.push(0);
        return OK;
    }
    int num2Max = NUM_MAX / abs(num1);
    if (abs(num2) > num2Max)
        return ERROR;
    int result = num1 * num2;
    stack_num.push(result);
    return OK;
}

int funcDIV()
{
    if (stack_num.size() < 2)
        return ERROR;
    int num1 = stack_num.top();
    stack_num.pop();
    int num2 = stack_num.top();
    stack_num.pop();

    if (num1 == 0 || (abs(num2) / abs(num1)) > NUM_MAX)
        return ERROR;
    if (num2 == 0)
        stack_num.push(0);
    else
    {
        int positive = (num1 / abs(num1)) * (num2 / abs(num2));
        int result = (abs(num2) / abs(num1)) * positive;
        stack_num.push(result);
    }
    return OK;
}

int funcMOD()
{
    if (stack_num.size() < 2)
        return ERROR;
    int num1 = stack_num.top();
    stack_num.pop();
    int num2 = stack_num.top();
    stack_num.pop();

    if (num1 == 0 || abs(num2 % num1) > NUM_MAX)
        return ERROR;
    int result = num2 % num1;
    stack_num.push(result);
    return OK;
}

void funcEND()
{
    if (stack_num.size() == 1)
        cout << stack_num.top() << "\n";
    else
        cout << "ERROR\n";
}

void runProgram(int initNum)
{
    stack_num = stack<int>({initNum});
    numIndex = 0;
    int result = OK;
    for (int cmd : v_command)
    {
        switch (cmd)
        {
        case NUM:
            result = funcNUM();
            break;
        case POP:
            result = funcPOP();
            break;
        case INV:
            result = funcINV();
            break;
        case DUP:
            result = funcDUP();
            break;
        case SWP:
            result = funcSWP();
            break;
        case ADD:
            result = funcADD();
            break;
        case SUB:
            result = funcSUB();
            break;
        case MUL:
            result = funcMUL();
            break;
        case DIV:
            result = funcDIV();
            break;
        case MOD:
            result = funcMOD();
            break;
        case END:
            funcEND();
            break;
        default:
            assert(true);
            break;
        }
        if (result == ERROR)
        {
            cout << "ERROR\n";
            break;
        }
    }
}

int solution()
{
    while (true)
    {
        int cmd = NUM;
        v_num.resize(0);
        v_command.resize(0);
        while (cmd != END)
        {
            cmd = getCommand();
            v_command.push_back(cmd);
            if (cmd == NUM)
            {
                int num;
                cin >> num;
                v_num.push_back(num);
            }
            if (cmd == QUIT)
                return 0;
        }
        
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int initNum;
            cin >> initNum;
            runProgram(initNum);
        }
        cout << "\n";
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