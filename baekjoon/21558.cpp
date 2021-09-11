#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tribe_sizes;
int total_size;
vector<int> divisors;
vector<int> stones_to_max;

void find_divisors()
{
    for (int i = 1; i <= total_size; i++)
    {
        if (total_size % i == 0)
            divisors.push_back(i);
    }
}

int solution()
{
    // input
    cin >> N;
    tribe_sizes.resize(N + 1);
    stones_to_max.resize(N);
    total_size = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> tribe_sizes[i];
        total_size += tribe_sizes[i];
    }

    // solution
    find_divisors();

    for (auto divisor : divisors)
    {
        int sum = 0;
        int stone_count = N;
        for(int i = 1; i <= N; i++)
        {
            sum += tribe_sizes[i];
            if(sum % divisor == 0)
                stone_count--;
        }
        for(int i = stone_count; i < N; i++)
        {
            stones_to_max[i] = divisor;
        }
    }

    // output
    for(int i = 0; i < N; i++)
    {
        cout << stones_to_max[i] << " ";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}