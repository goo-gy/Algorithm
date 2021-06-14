#include <cstdio>
#include <vector>
using namespace std;

int test_case();
int read_input();
int print_output(long long result);
long long solution();
int T;
int N;
vector<int> sticker_board[2];
vector<int> dp_score[3];

int main()
{
    test_case();
    return 0;
}

long long solution()
{
    dp_score[0][0] = 0;
    dp_score[1][0] = sticker_board[0][0];
    dp_score[2][0] = sticker_board[1][0];

    for(int i = 1; i < N; i++)
    {
        int max_01 = max(dp_score[0][i-1], dp_score[1][i-1]);
        int max_02 = max(dp_score[0][i-1], dp_score[2][i-1]);

        dp_score[0][i] = max(max_01, max_02);
        dp_score[1][i] = max_02 + sticker_board[0][i];
        dp_score[2][i] = max_01 + sticker_board[1][i];
    }
    return max(max(dp_score[0][N-1], dp_score[1][N-1]), dp_score[2][N-1]);
}

int test_case()
{
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        read_input();
        long long result = solution();
        print_output(result);
    }
}

int read_input()
{
    scanf("%d", &N);
    sticker_board[0].resize(N);
    sticker_board[1].resize(N);
    dp_score[0].resize(N);
    dp_score[1].resize(N);
    dp_score[2].resize(N);
    for(int i = 0; i < N; i ++)
    {
        scanf("%d", &sticker_board[0][i]);
    }
    for(int i = 0; i < N; i ++)
    {
        scanf("%d", &sticker_board[1][i]);
    }
    return 0;
}

int print_output(long long result)
{
    printf("%lld\n", result);
    return 0;
}