#include <iostream>
#include <vector>
using namespace std;

int N;

#include <queue>
int R, C;
pair<int, int> moves[] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
vector<vector<int>> board;
vector<vector<bool>> visited;

void initialize_board()
{
    board.resize(R + 1);
    visited.resize(R + 1);
    for (int i = 1; i <= R; i++)
    {
        board[i].resize(C + 1);
        visited[i].resize(C + 1);
    }
}

bool check_range(pair<int, int> p)
{
    return (p.first >= 1 && p.second >= 1 && p.first <= R && p.second <= C);
}


int BFS(pair<int, int> start)
{
    queue<pair<int, int>> node_queue;
    node_queue.push(start);

    // initialize
    visited[start.first][start.second] = true;
    
    while(!node_queue.empty())
    {
        pair<int, int> current = node_queue.front();
        node_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {current.first + moves[i].first, current.second + moves[i].second};
            if(check_range(next) && !visited[next.first][next.second])
            {
                // do something
                visited[next.first][next.second] = true;
                node_queue.push(next);
            }
        }
    }
    return 0;
}

int solution()
{
    // input
    cin >> N;

    // solution

    // output
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}