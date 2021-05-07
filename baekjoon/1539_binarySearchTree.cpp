#include <iostream>
#include <vector>
#include<map>
using namespace std;

int read_input();
int print_output(long long result);
long long solution();
int N;

vector<int> numbers;

int main()
{
    read_input();
    long long result = solution();
    print_output(result);
    return 0;
}

long long solution()
{
    map<int, int> black_red_tree;
    long long depth_sum = 0;
    for (int i = 0; i < N; i++)
    {
        map<int, int>::iterator iter_right = black_red_tree.lower_bound(numbers[i]);
        map<int, int>::iterator iter_left = iter_right;
        int depth = 0;
        if(iter_left != black_red_tree.begin())
        {
            iter_left--;
            depth = iter_left->second;
        }
        if(iter_right != black_red_tree.end())
        {
            depth = max(depth, iter_right->second);
        }
        depth += 1;
        black_red_tree.insert(make_pair(numbers[i], depth));    
        depth_sum += depth;
    }
    return depth_sum;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    return 0;
}

int print_output(long long result)
{
    cout << result << "\n";
    return 0;
}