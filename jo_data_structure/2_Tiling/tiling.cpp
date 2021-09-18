#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> horizontal;
vector<int> vertical;

int solution()
{
    // input
    int length;
    int max_length = 0;
    do {
        cin >> length;
        horizontal.push_back(length);
        max_length = max(max_length, length);
    } while(length);

    // solution
    vertical.resize(max_length + 1, 0);
    for(int i = 0; i < horizontal.size(); i++)
    {
        for(int j = 0; j < horizontal[i]; j++)
        {
            vertical[j]++;
        }
    }
    
    // output
    for(int i = 0; i < vertical.size(); i++)
    {
        cout << vertical[i] << " ";
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