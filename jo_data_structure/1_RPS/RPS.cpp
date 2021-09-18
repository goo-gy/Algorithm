#include <vector>
#include <iostream>

using namespace std;

char hands[2];
vector<bool> used;
// R P S with ascii

int read_input();
int write_output(const char answer);
char solution();

int main()
{
    read_input();
    char result = solution();
    write_output(result);
    return 0;
}

char solution()
{
    if(hands[0] == hands[1])
        return 'D';

    used.resize(150, false);

    for (int i = 0; i < 2; i++)
    {
        used[hands[i]] = true;
    }

    if (!used['R'])
        return 'S';
    else if (!used['P'])
        return 'R';
    else if(!used['S'])
        return 'P';
    return ' ';
}

int read_input()
{
    for (int i = 0; i < 2; i++)
    {
        cin >> hands[i];
    }
    return 0;
}

int write_output(const char answer)
{
    cout << answer;
    return 0;
}