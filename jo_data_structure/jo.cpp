#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;

struct compare {
    bool operator() (const int &left, const int &right){
        return left < right;    
    }
};

void solution()
{
    int thedata[] = {145, 232, 123, 34, 1324};
    priority_queue<int, vector<int>, compare> pq1(thedata, thedata+4);

    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;

}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N;
}

void output()
{
}

int main()
{
    solution();
    output();
    return 0;
}