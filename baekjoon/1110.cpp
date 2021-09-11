#include <iostream>
#include <vector>
using namespace std;

int N;

int solution()
{
    // input
    cin >> N;

    // solution
    int count = 0;
    int current_number = N;
    while(true)
    {
        if(current_number < 10)
            current_number *= 10;
        
        int new_number = (current_number % 10)*10 + (current_number / 10 + current_number % 10)%10;
        count++;
        break;
        if(new_number == N)
            break;
        current_number = new_number;
        cout << current_number << endl;
    }

    // output
    cout << count << endl;
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}