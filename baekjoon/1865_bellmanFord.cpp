#include <iostream>
#include <vector>
#include <tuple>

#define INF 987654321
enum
{
    SRC,
    DST,
    COST
};

using namespace std;

int N, M, W;
vector<long long> v_distance;
vector<tuple<int, int, int>> v_edge;

bool updateDistance()
{
    bool isUpdated = false;
    for (auto edge : v_edge)
    {
        long long newDistance = v_distance[get<SRC>(edge)] + get<COST>(edge);
        if (newDistance < v_distance[get<DST>(edge)])
        {
            v_distance[get<DST>(edge)] = newDistance;
            isUpdated = true;
        }
    }
    return isUpdated;
}

bool findNegativeCycle()
{
    for (int i = 1; i <= N - 1; i++)
        updateDistance();
    return updateDistance();
}

void solution()
{
    cin >> N >> M >> W;
    v_distance.resize(N + 1, INF);
    for (int i = 1; i <= M; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        v_edge.push_back(make_tuple(src, dst, cost));
        v_edge.push_back(make_tuple(dst, src, cost));
    }
    for (int i = 1; i <= W; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        v_edge.push_back(make_tuple(src, dst, -cost));
    }
    bool haveNegativeCycle = findNegativeCycle();
    if (haveNegativeCycle)
        cout << "Yes\n";
    else
        cout << "NO\n";
}

void reset()
{
    v_distance.clear();
    v_edge.clear();
}

void test_case()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solution();
        reset();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_case();
    return 0;
}