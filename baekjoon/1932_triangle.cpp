#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<vector<int>> number_tree;
vector<vector<int>> sum_tree;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    for(int i = N - 2; i >= 0; i--)
    {
        for(int k = 0; k < i + 1; k++)
        {
            sum_tree[i][k] += max(sum_tree[i+1][k], sum_tree[i+1][k+1]);
        }
    }
    return sum_tree[0][0];
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    number_tree.resize(N);
    sum_tree.resize(N);
    for(int i = 0; i < N; i++)
    {
        number_tree[i].resize(i+1);
        sum_tree[i].resize(i+1, 0);
        for(int k = 0; k <= i; k++)
        {
            cin >> number_tree[i][k];
            sum_tree[i][k] = number_tree[i][k];
        }
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}