#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
struct Schedule {
    int days;
    int price;
};
vector<vector<Schedule>> schedule_list;
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
        dp_price[i] = dp_price[i-1];
        for(int k = 0; k < schedule_list[i].size(); k++)
        {
            int new_price = schedule_list[i][k].price + dp_price[i - schedule_list[i][k].days];
            if(new_price > dp_price[i])
                dp_price[i] = new_price;
        }
    }
    return dp_price[N];
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    schedule_list.resize(N+1);
    dp_price.resize(N+1);
    for(int i = 0; i < N; i++)
    {
        Schedule schedule;
        cin >> schedule.days >> schedule.price;
        if(i + schedule.days <= N)
            schedule_list[i + schedule.days].push_back(schedule);
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}