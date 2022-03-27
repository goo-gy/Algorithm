#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, knowCount;
vector<vector<int>> vv_connect;
vector<bool> v_people;
vector<vector<int>> vv_party;

void connect_people()
{
    for (auto v_party : vv_party)
    {
        for (int i = 0; i < v_party.size(); i++)
        {
            for (int j = i + 1; j < v_party.size(); j++)
            {
                int person1 = v_party[i];
                int person2 = v_party[j];
                vv_connect[person1].push_back(person2);
                vv_connect[person2].push_back(person1);
            }
        }
    }
}

int countParty()
{
    int count = 0;
    for (auto v_party : vv_party)
    {
        int canLie = true;
        for (int i = 0; i < v_party.size(); i++)
        {
            int person = v_party[i];
            if (v_people[person])
            {
                canLie = false;
                break;
            }
        }
        if (canLie)
            count++;
    }
    return count;
}

void BFS(int start)
{
    queue<int> q;
    vector<bool> v_visited(N + 1, false);
    q.push(start);
    v_visited[start] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int next : vv_connect[current])
        {
            if (!v_visited[next])
            {
                v_visited[next] = true;
                v_people[next] = true;
                q.push(next);
            }
        }
    }
}

void solution()
{
    cin >> N >> M;
    vv_connect.resize(N + 1);
    v_people.resize(N + 1);

    cin >> knowCount;
    for (int i = 1; i <= knowCount; i++)
    {
        int person;
        cin >> person;
        v_people[person] = true;
    }
    for (int i = 1; i <= M; i++)
    {
        int count;
        cin >> count;
        vector<int> v_party;
        for (int i = 1; i <= count; i++)
        {
            int person;
            cin >> person;
            v_party.push_back(person);
        }
        vv_party.push_back(v_party);
    }
    connect_people();
    for (int i = 1; i <= N; i++)
    {
        if (v_people[i])
            BFS(i);
    }
    int count = countParty();
    cout << count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}