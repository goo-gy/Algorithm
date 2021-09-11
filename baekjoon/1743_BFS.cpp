#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
vector<vector<bool>> area;
vector<pair<int, int>> wastes;


int move_x[] = { 0, 1, 0, -1};
int move_y[] = {-1, 0, 1, 0};

bool check_range(pair<int, int> p)
{
    return (p.first >= 1 && p.second >= 1 && p.first <= N && p.second <= M);
}

int BFS(pair<int, int> start)
{
    if(!area[start.first][start.second])
    {
        return 0;
    }
    queue<pair<int, int>> node_queue;
    node_queue.push(start);

    // initialize
    int waste_size = 1;
    area[start.first][start.second] = false;
    while(!node_queue.empty())
    {
        pair<int, int> current = node_queue.front();
        node_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = make_pair(current.first + move_x[i], current.second + move_y[i]);
            if(check_range(next) && area[next.first][next.second])
            {
                // do something
                area[next.first][next.second] = false;
                waste_size++;
                node_queue.push(next);
            }
        }
    }
    return waste_size;
}

int solution()
{
    // input
    cin >> N >> M >> K;
    area.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        area[i].resize(M + 1, false);
    }
    for (int i = 0; i < K; i++)
    {
        int row, col;
        cin >> row >> col;
        area[row][col] = true;
        wastes.push_back(make_pair(row, col));
    }

    // solution
    int biggest_waste = 0;
    for(int i = 0; i < K; i++)
    {
        biggest_waste = max(biggest_waste, BFS(wastes[i]));
    }

    // output
    cout << biggest_waste << endl;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}