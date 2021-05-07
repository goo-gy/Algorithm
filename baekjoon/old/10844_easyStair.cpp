#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<int> number_board;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    return 0;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    number_board.resize(N);
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}