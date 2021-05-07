#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<int> count_zero_map;
vector<int> count_one_map;

int read_input();
int print_output(pair<int, int> result);
pair<int, int> fibonacci(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        read_input();
        pair<int, int> result = fibonacci(N);
        print_output(result);
    }
    return 0;
}

int read_input()
{
    cin >> N;
    count_zero_map.resize(N + 1, 0);
    count_one_map.resize(N + 1, 0);
    return 0;
}

int print_output(pair<int, int> result)
{
    cout << result.first << " " << result.second << "\n";
    return 0;
}

pair<int, int> fibonacci(int n)
{
    count_zero_map[0] = 1;
    count_one_map[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        count_zero_map[i] = count_zero_map[i - 1] + count_zero_map[i - 2];
        count_one_map[i] = count_one_map[i - 1] + count_one_map[i - 2];
    }
    return make_pair(count_zero_map[n], count_one_map[n]);
}