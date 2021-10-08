#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N;
vector<queue<int>> v_q_plane;
vector<int> answers;

void solution();
void pre_setting();
void input();
void output();

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_waiting;
bool add_plane(int runway)
{
    if (!v_q_plane[runway].empty())
    {
        int plane_id = v_q_plane[runway].front();
        v_q_plane[runway].pop();
        pq_waiting.push(make_pair(plane_id, runway));
        return true;
    }
    return false;
}

void solution()
{
    for (int i = 0; i < N; i++)
    {
        add_plane(i);
    }
    while (!pq_waiting.empty())
    {
        pair<int, int> out = pq_waiting.top();
        pq_waiting.pop();
        answers.push_back(out.first);
        int runway = out.second;
        add_plane(runway);
    }
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N;
    v_q_plane.resize(N);
    for (int i = 0; i < N; i++)
    {
        while (true)
        {
            int plane_id;
            cin >> plane_id;
            if (plane_id == 0)
                break;
            v_q_plane[i].push(plane_id);
        }
    }
}

void output()
{
    for (auto answer : answers)
    {
        cout << answer << "\n";
    }
}