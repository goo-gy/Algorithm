#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#define N 5
#define R 5

vector<int> v_num = {1, 2, 3, 4, 5};
vector<int> result;
vector<bool> visited;

void print_result()
{
    for (int num : result)
        cout << num << " ";
    cout << "\n";
}

void permutation(int depth)
{
    if (R < depth)
    {
        print_result();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            result.push_back(v_num[i]);
            permutation(depth + 1);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int solution()
{
    visited.resize(N);
    permutation(1);
    return 0;
}

int main()
{
    solution();
    return 0;
}