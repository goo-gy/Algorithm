#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

#define tup_cii tuple<char, int, int> // gender, order, number

using namespace std;

int N;
priority_queue<tup_cii, vector<tup_cii>> q_old;
priority_queue<tup_cii, vector<tup_cii>, greater<tup_cii>> q_adult;
queue<tup_cii> q_child;

void solution();
void pre_setting();
void input();
void output();

int main()
{
    pre_setting();
    input();
    output();
    return 0;
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int number, age;
        char gender;
        cin >> number >> age >> gender;
        if (age <= 15)
            q_child.push(make_tuple(gender, i, number));
        else if (age <= 60)
            q_adult.push(make_tuple(gender, i, number));
        else
            q_old.push(make_tuple(gender, -i, number));
    }
}

void output()
{
    while (!q_old.empty())
    {
        tup_cii old = q_old.top();
        q_old.pop();
        cout << get<2>(old) << "\n";
    }
    while (!q_child.empty())
    {
        tup_cii child = q_child.front();
        q_child.pop();
        cout << get<2>(child) << "\n";
    }
    while (!q_adult.empty())
    {
        tup_cii adult = q_adult.top();
        q_adult.pop();
        cout << get<2>(adult) << "\n";
    }
}