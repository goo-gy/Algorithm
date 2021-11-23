#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int L, C;
vector<char> v_charDic;
vector<char> v_char_candi;
set<char> set_vowel = {'a', 'e', 'i', 'o', 'u'};

int cons_count = 0;
int vowel_count = 0;

bool check_vowel(char selected)
{
    if(set_vowel.find(selected) == set_vowel.end())
        return false;
    else
        return true;
}

void get_candidate(int index, int depth)
{
    if(depth == L)
    {
        if(cons_count >= 2 && vowel_count >= 1)
            cout << string(v_char_candi.begin(), v_char_candi.end()) << endl;
        return;
    }
    for(int i = index; i < v_charDic.size(); i++)
    {
        bool is_vowel = check_vowel(v_charDic[i]);
        v_char_candi.push_back(v_charDic[i]);
        is_vowel ? vowel_count++ : cons_count++;
        get_candidate(i + 1, depth + 1);
        is_vowel ? vowel_count-- : cons_count--;
        v_char_candi.pop_back();
    }
    
}

int solution()
{
    // input
    cin >> L >> C;
    v_charDic.resize(C);
    for(auto &char_candi : v_charDic)
        cin >> char_candi;

    // solution
    sort(v_charDic.begin(), v_charDic.end());
    get_candidate(0, 0);
    
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}