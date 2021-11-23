#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
list<int> li_deck;

void solution();
void pre_setting();
void input();
void output();

int main()
{
    pre_setting();
    input();
    solution();
    output();
    return 0;
}

void shuffle()
{
    // divide
    list<int> li_end;
    auto it_middle = li_deck.begin();
    advance(it_middle, N / 2);
    li_end.splice(li_end.end(), li_deck, it_middle, li_deck.end());

    // merge
    auto iter_pos = li_deck.begin();
    for (auto iter = li_end.begin(); iter != li_end.end(); iter++)
        li_deck.insert(++iter_pos, *iter);
}

void cut(int start, int end)
{
    auto it_start = li_deck.begin();
    advance(it_start, start);
    auto it_end = it_start;
    advance(it_end, end - start);
    li_deck.splice(li_deck.end(), li_deck, it_start, it_end);
}

void solution()
{
    for (int i = 1; i <= K; i++)
    {
        string command;
        cin >> command;
        if (command[0] == 'C')
        {
            int start, end;
            cin >> start >> end;
            cut(start - 1, end);
        }
        else
            shuffle();
    }
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        li_deck.push_back(i);
    }
}

void output()
{
    auto iter = li_deck.begin();
    cout << *iter << " ";
    advance(iter, N/2 - 1);
    cout << *iter << " ";
    cout << *li_deck.rbegin() << endl;
}