#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;

struct ScoreLength{
    int score;
    int length;
};

vector<int> numbers;
vector<ScoreLength> sequence_board;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    sequence_board[0].length = 0;
    sequence_board[0].score = 0;

    int total_max_length = 0;
    for(int i = 1; i <= N; i++)
    {
        int max_length = 0;
        for(int k = 0; k < i; k++)
        {
            if(sequence_board[k].score < numbers[i])
                max_length = max(max_length, sequence_board[k].length);
        }
        sequence_board[i].score = numbers[i];
        sequence_board[i].length = max_length +1;

        if(sequence_board[i].length > total_max_length)
            total_max_length = sequence_board[i].length;
    }
    return total_max_length;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    numbers.resize(N+1);
    sequence_board.resize(N+1);
    for(int i = 1; i <= N; i++)
    {
        cin >> numbers[i];
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}