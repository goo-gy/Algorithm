#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int numCount;
vector<string> v_str;
vector<bool> v_visited;
set<string> set_permu;

void permuation(int N, int K, string str_permu)
{
    if (K == 0 && set_permu.count(str_permu) == 0)
    {
        set_permu.insert(str_permu);
        numCount++;
    }

    for (int i = 0; i < N; i++)
    {
        if (!v_visited[i])
        {
            v_visited[i] = true;
            permuation(N, K - 1, str_permu + v_str[i]);
            v_visited[i] = false;
        }
    }
}

int solution()
{
    int N, K;
    cin >> N >> K;
    v_visited.resize(N);
    for (int i = 1; i <= N; i++)
    {
        string str_num;
        cin >> str_num;
        v_str.push_back(str_num);
    }
    permuation(N, K, "");
    cout << numCount << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}