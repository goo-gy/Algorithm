#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str1, str2;
vector<vector<int>> DP;

int solution()
{
    // input
    cin >> str1 >> str2;
    DP.resize(str1.size() + 1);
    for(auto &row : DP)
        row.resize(str2.size() + 1, 0);

    // solution
    int maxLen = 0;
    for (int row = 1; row <= str1.size(); row++)
    {
        for (int col = 1; col <= str2.size(); col++)
        {
            if(str1[row - 1] == str2[col - 1])
            {
                DP[row][col] = DP[row - 1][col - 1] + 1;
                maxLen = max(maxLen, DP[row][col]);
            }
            else
                DP[row][col] = 0;
        }
    }

    // output
    cout << maxLen;
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}