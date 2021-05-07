#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<int> stairs;
vector<int> record_single;
vector<int> record_doubled;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    //record_single[0] = 0;
    //record_doubled[0] = 0;
    record_single[1] = stairs[1];
    record_doubled[1] = 0;
    for(int i = 2; i <= N; i++)
    {
        record_single[i] = max(record_single[i-2], record_doubled[i-2]) + stairs[i];
        record_doubled[i] = record_single[i-1] + stairs[i];
    }
    return max(record_single[N], record_doubled[N]);
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    stairs.resize(N+1, 0);
    record_single.resize(N+1, 0);
    record_doubled.resize(N+1, 0);
    for(int i = 1; i <= N; i++)
    {
        cin >> stairs[i];
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}