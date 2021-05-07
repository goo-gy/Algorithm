#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<int> card_set;
vector<int> dp_price;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    for(int i = 1; i <= N; i++)
    {
        int max_price = 0;
        for(int k = 1; k <= i; k++)
        {
            int new_set_price = dp_price[i-k] + card_set[k];
            if(new_set_price > max_price)
                max_price = new_set_price;
        }
        dp_price[i] = max_price;
    }
    return dp_price[N];
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    card_set.resize(N+1);
    dp_price.resize(N+1);
    for(int i = 1; i <= N; i++)
    {
        cin >> card_set[i];
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}