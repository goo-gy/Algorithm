#include <iostream>
#include <vector>
using namespace std;

int N;
vector<char> balls;

int moving_count(bool toLeft)
{
    int initial = toLeft ? 0 : N - 1;
    int end = toLeft ? N : -1;
    int direction = toLeft ? 1 : - 1;
    

    bool have_red = false;
    bool have_blue = false;
    int red_count = 0;
    int blue_count = 0;
    for(int i = initial; i != end; i += direction)
    {
        if(balls[i] == 'R')
        {
            if(have_blue)
                red_count++;
            have_red = true;
        } else 
        {
            if(have_red)
                blue_count++;
            have_blue = true;
        }
    }
    return min(red_count, blue_count);
}

int solution()
{
    // input
    cin >> N;
    balls.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> balls[i];
    }

    // solution
    int leftCount = moving_count(true);
    int rightCount = moving_count(false);

    // output
    cout << min(leftCount, rightCount) << "\n";
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}