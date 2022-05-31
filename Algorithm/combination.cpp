#include <iostream>
#include <vector>
using namespace std;

#define N 5
#define R 4

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