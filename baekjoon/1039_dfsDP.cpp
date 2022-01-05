#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

string N;
int K;

string strMax;
set<pair<string, int>> set_visited;
bool reached = false;

string swap(string str, int i, int j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    return str;
}

void permutation(string str, int depth)
{
    auto iter = set_visited.find(make_pair(str, depth));
    if(iter != set_visited.end())
        return;
    set_visited.insert(make_pair(str, depth));

    if(depth == K)
    {
        reached = true;
        strMax = max(strMax, str);
        return;
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i + 1; j < str.size(); j++)
        {
            string strSwaped = swap(str, i , j);
            if(strSwaped[0] != '0')
                permutation(strSwaped, depth + 1);
        }
    }
}

int solution()
{
    // input
    cin >> N >> K;

    // solution
    permutation(N, 0);

    // output
    if(reached)
        cout << strMax << "\n";
    else
        cout << "-1\n";
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}