#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

void solution()
{
    cin >> N;
    vector<pair<int, int>> v_num(N);
    vector<pair<int, int>> v_result(N);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v_num[i] = make_pair(num, i);
    }
    sort(v_num.begin(), v_num.end());
    int count = 0;
    v_result[0] = make_pair(v_num[0].second, 0);
    for (int i = 1; i < N; i++)
    {
        if (v_num[i].first > v_num[i - 1].first)
            count++;
        v_result[i] = make_pair(v_num[i].second, count);
    }
    sort(v_result.begin(), v_result.end());
    for (auto result : v_result)
        cout << result.second << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}