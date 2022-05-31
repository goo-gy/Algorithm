#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void print_result(vector<int> &v_selected)
{
    for (int num : v_selected)
    {
        cout << num << " ";
    }
    cout << '\n';
}

void permutation(vector<int> &v_num, vector<bool> &v_visited, vector<int> &v_selected)
{
    if (v_selected.size() == v_num.size())
    {
        print_result(v_selected);
        return;
    }

    for (int i = 0; i < v_num.size(); i++)
    {
        if (!v_visited[i])
        {
            v_visited[i] = true;
            v_selected.push_back(v_num[i]);
            permutation(v_num, v_visited, v_selected);
            v_selected.pop_back();
            v_visited[i] = false;
        }
    }
}

int solution()
{
    vector<int> v_num = {1, 2, 3, 4, 5};
    vector<bool> v_visited(v_num.size(), false);
    vector<int> v_selected;

    permutation(v_num, v_visited, v_selected);
    return 0;
}

int main()
{
    solution();
    return 0;
}