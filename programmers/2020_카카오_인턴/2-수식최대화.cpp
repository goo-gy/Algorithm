#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<vector<int>> vv_priority = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0},
};
map<char, int> map_opNum;

long long calculate(string expression)
{
}

class parseTree
{
};

long long
solution(string expression)
{
    map_opNum['+'] = 0;
    map_opNum['-'] = 1;
    map_opNum['*'] = 2;

    for (vector<int> v_priority : vv_priority)
    {
        long long result = calculate(expression);
    }

    long long answer = 0;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long result = solution("100-200*300-500+20");
    cout << result << endl;
    return 0;
}