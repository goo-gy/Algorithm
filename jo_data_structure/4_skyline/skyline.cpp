#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int N;

int skyline_start;
int skyline_end;
int skylines[1000000];

void solution();
void pre_setting();
void output();

int main()
{
    pre_setting();
    solution();
    output();
    return 0;
}

void solution()
{
    cin >> N;
    skyline_start = 1000000;
    skyline_end = 0;
    for (int i = 0; i < N; i++)
    {
        int x, vertical, horizon;
        cin >> x >> vertical >> horizon;
        for (int k = x; k < x + horizon; k++)
        {
            skylines[k] = max(skylines[k], vertical);
        }
        skyline_start = min(skyline_start, x);
        skyline_end = max(skyline_end, x + horizon);
    }
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(skylines, 0, 1000000 * sizeof(int));
}

void output()
{
    int height_prev = 0;
    int current_length = skyline_start;
    for (int i = skyline_start; i <= skyline_end; i++)
    {
        if(height_prev != skylines[i])
        {
            cout << current_length << " " << skylines[i] - height_prev << " ";
            height_prev = skylines[i];
            current_length = 0;
        }
        current_length ++;        
    }
}