#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

enum Direction
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

int N, M;
vector<vector<char>> board;
bool visited[10][10][10][10];

tuple<int, int, int, int, int> rotate(tuple<int, int, int, int, int> current, int direction)
{
    int move_size = 1;
    int red_row = get<0>(current);
    int red_col = get<1>(current);
    int blue_row = get<2>(current);
    int blue_col = get<3>(current);
    int moves = get<4>(current);

    switch (direction)
    {
    case UP:
        move_size = -1;
    case DOWN:
        while (board[blue_row][blue_col] != '#')
        {
            if (board[blue_row][blue_col] == 'O')
                return make_tuple(-1, -1, -1, -1, moves + 1);
            blue_row += move_size;
        }
        while (board[red_row][red_col] != '#')
        {
            if (board[red_row][red_col] == 'O')
                return make_tuple(0, 0, 0, 0, moves + 1);
            red_row += move_size;
        }
        red_row -= move_size;
        blue_row -= move_size;
        if (red_row == blue_row && red_col == blue_col)
        {
            if ((get<0>(current) < get<2>(current) && direction == DOWN) || (get<0>(current) > get<2>(current) && direction == UP))
                red_row -= move_size;
            else
                blue_row -= move_size;
        }
        break;
    case LEFT:
        move_size = -1;
    case RIGHT:
        while (board[blue_row][blue_col] != '#')
        {
            if (board[blue_row][blue_col] == 'O')
                return make_tuple(-1, -1, -1, -1, moves + 1);
            blue_col += move_size;
        }
        while (board[red_row][red_col] != '#')
        {
            if (board[red_row][red_col] == 'O')
                return make_tuple(0, 0, 0, 0, moves + 1);
            red_col += move_size;
        }
        red_col -= move_size;
        blue_col -= move_size;
        if (red_row == blue_row && red_col == blue_col)
        {
            if ((get<1>(current) < get<3>(current) && direction == RIGHT) || (get<1>(current) > get<3>(current) && direction == LEFT))
                red_col -= move_size;
            else
                blue_col -= move_size;
        }
        break;
    }
    return make_tuple(red_row, red_col, blue_row, blue_col, moves + 1);
}

int BFS(tuple<int, int, int, int, int> start)
{
    queue<tuple<int, int, int, int, int>> next_queue;
    next_queue.push(start);
    while (!next_queue.empty())
    {
        tuple<int, int, int, int, int> current = next_queue.front();
        next_queue.pop();
        int red_row = get<0>(current);
        int red_col = get<1>(current);
        int blue_row = get<2>(current);
        int blue_col = get<3>(current);
        int moves = get<4>(current);
        if(moves >= 10)
            return -1;
        if (visited[red_row][red_col][blue_row][blue_col])
            continue;
        visited[red_row][red_col][blue_row][blue_col] = true;

        for (int i = 0; i < 4; i++)
        {
            tuple<int, int, int, int, int> next = rotate(current, i);
            int result = get<0>(next);
            if (result == 0)
                return get<4>(next);
            else if (result != -1)
                next_queue.push(next);
        }
    }
    return -1;
}

int solution()
{
    // input
    cin >> N >> M;
    board.resize(N);
    pair<int, int> red;
    pair<int, int> blue;
    for (int i = 0; i < N; i++)
    {
        board[i].resize(M);
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                red = make_pair(i, j);
            }
            else if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                blue = make_pair(i, j);
            }
        }
    }

    // solution
    int answer = BFS(make_tuple(red.first, red.second, blue.first, blue.second, 0));

    // output
    cout << answer << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}