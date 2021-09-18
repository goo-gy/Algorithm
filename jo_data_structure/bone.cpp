#include <vector>
#include <iostream>

using namespace std;

int N;
long long answer;

void solution();
void pre_setting();
void input();
void output();

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}

void solution()
{
    answer = 0;
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N;
}

void output()
{
    cout << answer;
}