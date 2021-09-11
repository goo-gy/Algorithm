#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> ways;

int solution()
{
    // input
    cin >> N;

    // solution
    ways.resize(N + 3);
    ways[1] = 1;
    ways[2] = 1;
    ways[3] = 2;
    for(int i = 4; i <= N; i++)
    {
        ways[i] = (ways[i - 1] + ways[i - 3]) % 1000000009; 
    }

    // output
    cout << ways[N] << "\n";
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}