#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <queue>

#define INF 123456789
#define SRC first
#define V_DST second

using namespace std;

int N;
array<char, 3> a_people;
vector<char> v_node;
map<char, vector<char>> m_v_graph;
array<array<int, 128>, 3> a_a_distance;

void BFS(char person, int personId)
{
    queue<pair<char, int>> q_node;
    q_node.push(make_pair(person, 3));

    a_a_distance[personId][person] = 0;
    while (!q_node.empty())
    {
        pair<char, int> p_cur = q_node.front();
        char current = p_cur.first;
        int distance = p_cur.second;
        q_node.pop();
        for (char next : m_v_graph[current])
        {
            if (a_a_distance[personId][next] == INF)
            {
                a_a_distance[personId][next] = distance - 2;
                q_node.push(make_pair(next, distance + 3));
            }
        }
    }
}

int getMaxDistance(char dst)
{
    int max_distance = 0;
    for (int i = 0; i < 3; i++)
        max_distance = max(max_distance, a_a_distance[i][dst]);
    return max_distance;
}

void solution()
{
    int i = 0;
    for (char person : a_people)
    {
        a_a_distance[i].fill(INF);
        BFS(person, i);
        i++;
    }

    char bestPlace;
    int min_distance = INF;
    for (char place : v_node)
    {
        int distance = getMaxDistance(place);
        if (distance < min_distance)
        {
            bestPlace = place;
            min_distance = distance;
        }
    }

    if(min_distance == INF)
        cout << '@' << "\n" << -1 << "\n";
    else  
        cout << bestPlace << "\n" << min_distance << "\n";
}


void add_edge(int src, int dst)
{
    auto it_src = m_v_graph.find(src);
    if (it_src == m_v_graph.end())
        m_v_graph[src] = vector<char>(1, dst);
    else
        it_src->V_DST.push_back(dst);
}

void input()
{
    cin >> N;
    for (char &person : a_people)
        cin >> person;
    for (int i = 1; i <= N; i++)
    {
        char src, dst;
        cin >> src;
        v_node.push_back(src);
        while(true)
        {
            cin >> dst;
            if (dst == '$')
                break;
            add_edge(src, dst);
        }
    }
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int main()
{
    pre_setting();
    input();
    solution();
    return 0;
}