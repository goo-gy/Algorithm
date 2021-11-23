#include <fstream>
#include <iostream>
#include <array>
#include <list>
#include <algorithm>
#include <string>

#define LCI list<char>::iterator
using namespace std;

array<string, 6> aCmd = {"front", "back", "cut", "double", "flip", "report"};
int N;
list<char> liGen;

int checkCmd(string cmd)
{
    int i = 0;
    for (int i = 0; i < aCmd.size(); i++)
    {
        if (cmd == aCmd[i])
            return i;
    }
    return -1;
}

void gDouble(LCI sta, LCI end)
{
    list<char> temp(sta, end);
    liGen.splice(sta, temp);
}

void gFlip(LCI sta, LCI end)
{
    list<char> temp;
    temp.splice(temp.end(), liGen, sta, end);
    temp.reverse();
    liGen.splice(end, temp);
}

void print(char one)
{
    cout << one;
}
void gReport(LCI sta, LCI end)
{
    if(sta == liGen.end())
    {
        cout << "NONE\n";
        return;
    }
    for_each(sta, end, print);
    cout << "\n";
}

pair<LCI, LCI> makeIter(int i, int j)
{
    if(i > liGen.size())
        return make_pair(liGen.end(), liGen.end());
    i--;
    LCI sta = liGen.begin();
    advance(sta, i);
    LCI end = sta;
    advance(end, (j - i));
    if(j > liGen.size())
        end = liGen.end();
    return make_pair(sta, end);
}

void solution()
{
    cin >> N;
    for (int k = 1; k <= N; k++)
    {
        string cmd;
        int i, j;
        cin >> cmd >> i >> j;
        int command_type = checkCmd(cmd);
        auto p_i = makeIter(i, j);
        LCI sta = p_i.first;
        LCI end = p_i.second;
        switch (command_type)
        {
            case 0: liGen.splice(liGen.begin(), liGen, sta, end); break;
            case 1: liGen.splice(liGen.end(), liGen, sta, end); break;
            case 2: liGen.erase(sta, end); break;
            case 3: gDouble(sta, end); break;
            case 4: gFlip(sta, end); break;
            case 5: gReport(sta, end); break;
            default: break;
        }
    }
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream in("/NESPA/sapiens.txt");
    string temp;
    string gen;
    if (in.is_open())
    {
        char c;
        getline(in, temp);
        while (!in.eof())
        {
            in >> gen;
            list<char> li_term(gen.begin(), gen.end());
            liGen.splice(liGen.end(), li_term);
        }
    }
}

int main()
{
    input();
    solution();
    return 0;
}