#include <iostream>
#include <vector>
#include <algorithm>

#define END first
#define BEGIN second

using namespace std;

int N;
vector<pair<int, int>> v_meeting;

void solution()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int begin, end;
        cin >> begin >> end;
        v_meeting.push_back(make_pair(end, begin));
    }
    sort(v_meeting.begin(), v_meeting.end());
    int count = 0;
    int now = 0;
    for (auto meeting : v_meeting)
    {
        if (meeting.BEGIN >= now)
        {
            count++;
            now = meeting.END;
        }
    }
    cout << count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}