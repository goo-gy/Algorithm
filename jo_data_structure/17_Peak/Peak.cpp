#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

#define PAIR_II pair<int, int>
#define TIME first
#define TYPE second

enum { TYPE_END = -1, TYPE_BEGIN = 1 };

using namespace std;

set<int> s_timeBound;
priority_queue<int, vector<int>, greater<int>> pq_timeBound;
priority_queue<PAIR_II, vector<PAIR_II>, greater<PAIR_II>> pq_event; // time, type
vector<int> v_timeBound;
vector<int> v_count;
int N;


void solution()
{
    v_count.resize(pq_timeBound.size(), 0);
    int i = 0;
    int countCur = 0;
    int timeCur = pq_timeBound.top();

    pq_timeBound.pop();
    v_timeBound.push_back(timeCur);
    while (!pq_event.empty())
    {
        const PAIR_II event = pq_event.top();
        if (event.TIME == timeCur)
        {
            countCur += event.TYPE;
            v_count[i] = countCur;
            pq_event.pop(); 
        }
        else
        {
            timeCur = pq_timeBound.top(); pq_timeBound.pop();
            v_timeBound.push_back(timeCur);
            i++;
        }
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
    for (int i = 1; i <= N; i++)
    {
        int begin, end;
        cin >> begin >> end;
        pq_event.push({begin, TYPE_BEGIN});
        pq_event.push({end, TYPE_END});

        if (s_timeBound.count(begin) == 0)
        {
            s_timeBound.insert(begin);
            pq_timeBound.push(begin);
        }
        if (s_timeBound.count(end) == 0)
        {
            s_timeBound.insert(end);
            pq_timeBound.push(end);
        }
    }
}

void output()
{
    tuple<int, int, int> peakTime = make_tuple(v_count[0], v_timeBound[1] - v_timeBound[0], v_timeBound[1]); // count, length, end
    for (int i = 1; i < v_count.size() - 1; i++)
    {
        tuple<int, int, int> newRange = make_tuple(v_count[i], v_timeBound[i + 1] - v_timeBound[i], v_timeBound[i + 1]);
        peakTime = max(peakTime, newRange);
    }
    cout << get<2>(peakTime) - get<1>(peakTime) << " " << get<2>(peakTime) << "\n";
}

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}