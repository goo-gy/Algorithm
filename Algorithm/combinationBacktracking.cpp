#include <iostream>
#include <vector>
using namespace std;

#define N 5
#define R 3

vector<int> v_num = {0, 1, 2, 3, 4};
vector<int> result;
vector<bool> visited;

void print_result()
{
    for (int num : result)
        cout << num << " ";
    cout << "\n";
}

void combination(int start)
{
    if (R == result.size())
    {
        print_result();
        return;
    }
    for (int i = start; i < N; i++)
    {
        if (N - i < R - result.size())
            return;
        result.push_back(v_num[i]);
        combination(i + 1);
        result.pop_back();
    }
}

int solution()
{
    visited.resize(N, false);
    combination(0);
    return 0;
}

int main()
{
    solution();
    return 0;
}