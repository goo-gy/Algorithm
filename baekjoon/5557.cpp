#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v_number;
int result;

unsigned long long cases = 0;
void find_case(int sum, int index)
{
    // check 
    int rest_count = N - index;
    if(sum < 0 || sum > 20)
        return;
    if(index == N && sum == result)
    {
        cases++;
        return;
    }

    find_case(sum + v_number[index], index + 1);
    find_case(sum - v_number[index], index + 1);
}

int solution()
{
    // input
    cin >> N;
    v_number.resize(N);
    for (int i = 1; i < N; i++)
    {
        cin >> v_number[i];
    }
    cin >> result;
    
    // solution
    find_case(v_number[1], 2);

    // output
    cout << cases << "\n";

    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}