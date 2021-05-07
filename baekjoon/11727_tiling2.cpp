#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;

vector<int> ways_map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    ways_map[0] = 1;
    ways_map[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        ways_map[i] = (ways_map[i - 1] + 2 * ways_map[i - 2]) % 10007;
    }
    return ways_map[N];
}

int read_input()
{
    cin >> N;
    ways_map.resize(N + 1, 0);
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}