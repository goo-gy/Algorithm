#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <queue>

#define INF         123456789
#define SRC         first
#define V_DST       second
#define NODE        first
#define DISTANCE    second

using namespace std;

array<char, 3> a_people;
vector<char> v_node;
map<char, vector<char>> m_v_graph;
map<char, array<int, 128>> m_a_distance;
pair<char, int> answer;

void input();
void solution();
void output();
void addEdge(int src, int dst);
void BFS(char person);
int  getMaxDistance(char dst);

int main()
{
    input();
    solution();
    output();
    return 0;
}

void input()
{
    int N;
    cin >> N;
    for (char &person : a_people)
    {
        cin >> person;
        m_a_distance[person] = {};
        m_a_distance[person].fill(INF);
    }
    v_node.resize(N);
    for (char &node : v_node)
    {
        cin >> node;
        while (true)
        {
            char dst;
            cin >> dst;
            if (dst == '$')
                break;
            addEdge(node, dst);
        }
    }
}

void addEdge(int src, int dst)
{
    auto iter = m_v_graph.find(src);
    if (iter == m_v_graph.end())
        m_v_graph[src] = vector<char>(1, dst);
    else
        iter->V_DST.push_back(dst);
}

void solution()
{
    for (char person : a_people)
        BFS(person);

    char bestPlace;
    int minDistance = INF;
    for (char place : v_node)
    {
        int distance = getMaxDistance(place);
        if (distance < minDistance)
        {
            bestPlace = place;
            minDistance = distance;
        }
    }

    if (minDistance == INF)
        answer = make_pair('@', -1);
    else
        answer = make_pair(bestPlace, minDistance);
}

void BFS(char person)
{
    queue<pair<char, int>> q_path;
    m_a_distance[person][person] = 0;
    
    q_path.push(make_pair(person, 1));
    while (!q_path.empty())
    {
        pair<char, int> cur = q_path.front(); q_path.pop();
        for (char next : m_v_graph[cur.NODE])
        {
            if (m_a_distance[person][next] == INF)
            {
                m_a_distance[person][next] = cur.DISTANCE;
                q_path.push(make_pair(next, cur.DISTANCE + 3));
            }
        }
    }
}

int getMaxDistance(char dst)
{
    int max_distance = 0;
    for (char person : a_people)
        max_distance = max(max_distance, m_a_distance[person][dst]);
    return max_distance;
}

void output()
{
    cout << answer.first << "\n" << answer.second << "\n";
}