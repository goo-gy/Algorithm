#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct RectByPoint
{
    double x1, y1, x2, y2;
};

struct Rect
{
    double center_x;
    double center_y;
    double half_x;
    double half_y;
};

RectByPoint P, Q;
Rect rectP, rectQ;

int solution()
{
    // input
    cin >> P.x1 >> P.y1 >> P.x2 >> P.y2;
    cin >> Q.x1 >> Q.y1 >> Q.x2 >> Q.y2;

    // solution
    rectP.center_x = (P.x1 + P.x2) / 2;
    rectP.center_y = (P.y1 + P.y2) / 2;
    rectP.half_x = P.x2 - rectP.center_x;
    rectP.half_y = P.y2 - rectP.center_y;

    rectQ.center_x = (Q.x1 + Q.x2) / 2;
    rectQ.center_y = (Q.y1 + Q.y2) / 2;
    rectQ.half_x = Q.x2 - rectQ.center_x;
    rectQ.half_y = Q.y2 - rectQ.center_y;

    double manhattan_x = fabs(rectP.center_x - rectQ.center_x);
    double manhattan_y = fabs(rectP.center_y - rectQ.center_y);

    if (manhattan_x < rectP.half_x + rectQ.half_x)
    {
        if (manhattan_y < rectP.half_y + rectQ.half_y)
            cout << "FACE\n";
        else if (manhattan_y > rectP.half_y + rectQ.half_y)
            cout << "NULL\n";
        else
            cout << "LINE\n";
    }
    else if (manhattan_x > rectP.half_x + rectQ.half_x)
    {
        cout << "NULL\n";
    }
    else
    {
        if (manhattan_y < rectP.half_y + rectQ.half_y)
            cout << "LINE\n";
        else if (manhattan_y > rectP.half_y + rectQ.half_y)
            cout << "NULL\n";
        else
            cout << "POINT\n";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}