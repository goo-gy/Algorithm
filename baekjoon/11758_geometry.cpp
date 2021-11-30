#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
};
vector<Point> v_point;

int solution()
{
    // input
    for (int i = 1; i <= 3; i++)
    {
        int x, y;
        cin >> x >> y;
        v_point.push_back({x, y});
    }
    v_point.push_back(v_point[0]);

    // solution
    int signedArea = 0;
    for (int i = 0; i < 3; i++)
    {
        signedArea += (v_point[i].x * v_point[i + 1].y);
        signedArea -= (v_point[i].y * v_point[i + 1].x);
    }

    // output
    if(signedArea > 0)
        cout << "1" << endl;
    else if(signedArea < 0)
        cout << "-1" << endl;
    else
        cout << "0" << endl;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}