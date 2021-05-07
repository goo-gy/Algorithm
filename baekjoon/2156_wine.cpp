#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<int> wine;

struct Drink_stack{
    int value[3];
};
vector<Drink_stack> drink_stacks;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    drink_stacks[0].value[0] = 0;
    drink_stacks[0].value[1] = wine[0];
    drink_stacks[0].value[2] = 0;

    for(int i = 1; i < N; i++)
    {
        drink_stacks[i].value[0] = max(max(drink_stacks[i-1].value[0], drink_stacks[i-1].value[1]), drink_stacks[i-1].value[2]);
        drink_stacks[i].value[1] = drink_stacks[i-1].value[0] + wine[i];
        drink_stacks[i].value[2] = drink_stacks[i-1].value[1] + wine[i];
    }
    return max(max(drink_stacks[N-1].value[0], drink_stacks[N-1].value[1]), drink_stacks[N-1].value[2]);
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    wine.resize(N);
    drink_stacks.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> wine[i];
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}