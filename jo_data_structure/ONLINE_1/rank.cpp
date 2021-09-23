#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
public:
    vector<int> v_score;
    string name;
};

int N;
vector<Student> v_student;

int student_bigger(Student &me, Student &other)
{
    if (me.v_score.size() > other.v_score.size())
        return true;
    if (me.v_score.size() < other.v_score.size())
        return false;

    for (int i = 0; i < me.v_score.size(); i++)
    {
        if (me.v_score[i] > other.v_score[i])
            return true;
        if (me.v_score[i] < other.v_score[i])
            return false;
    }

    if (me.name < other.name)
        return true;

    return false;
}

void solution()
{
    sort(v_student.begin(), v_student.end(), student_bigger);
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N;
    v_student.resize(N);
    for (int i = 0; i < N; i++)
    {
        string sname;
        cin >> v_student[i].name;

        while (1)
        {
            int score;
            cin >> score;
            if (score == 0)
                break;
            else
                v_student[i].v_score.push_back(score);
        }
        sort(v_student[i].v_score.begin(), v_student[i].v_score.end());
    }
}

void output()
{
    for (auto student : v_student)
    {
        cout << student.name << "\n";
    }
}

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}