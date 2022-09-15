#include <iostream>
#include <vector>

#define INF 1234567890

using namespace std;

int N, M;
vector<int> v_word;
long long DP[1001][1001];

void init()
{
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            DP[i][j] = INF;
        }
    }
}

long long getMinimum(int index, int used)
{
    if(index >= N)
        return 0;
    if(DP[index][used] != INF)
        return DP[index][used];

    long long minWasted = INF;
    int jump = used > 0 ? 1 : 0;
    if(used + v_word[index] + 1 <= M)
    {
        minWasted = min(minWasted, getMinimum(index + 1, (used + v_word[index] + jump) % M));
    }
    long long blank = M - used;
    minWasted = min(minWasted, getMinimum(index + 1, v_word[index]) + blank*blank);
    
    DP[index][used] = minWasted;
    return DP[index][used];
}

int solution()
{
    // input
    cin >> N >> M;
    v_word.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v_word[i];
    }
    
    // solution
    init();
    int result = getMinimum(0, 0);

    // output
    cout << result << "\n";
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}