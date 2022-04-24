#include <iostream>
#include <vector>

using namespace std;

#define LEFT 0
#define RIGHT 1
vector<pair<int, int>> v_position = {
    {3, 1},
    {0, 0},
    {0, 1},
    {0, 2},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 0},
    {2, 1},
    {2, 2},
};

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    bool isLeftHand = (hand == "left");
    pair<int, int> leftHand = make_pair(3, 0);
    pair<int, int> rightHand = make_pair(3, 2);

    for (int number : numbers)
    {
        int direction;
        pair<int, int> position = v_position[number];
        if (position.second == 0)
            direction = LEFT;
        else if (position.second == 2)
            direction = RIGHT;
        else
        {
            int distanceL = abs(leftHand.first - position.first) + abs(leftHand.second - position.second);
            int distanceR = abs(rightHand.first - position.first) + abs(rightHand.second - position.second);
            if (distanceL == distanceR)
                direction = isLeftHand ? LEFT : RIGHT;
            else
                direction = distanceL < distanceR ? LEFT : RIGHT;
        }
        if (direction == LEFT)
        {
            leftHand = position;
            answer += 'L';
        }
        else
        {
            rightHand = position;
            answer += 'R';
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string result = solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left");
    cout << result << endl;
    return 0;
}