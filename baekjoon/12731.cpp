#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int timeout;
int NA, NB;

int solution(int caseNumber)
{
    vector<int> srcA;
    vector<int> srcB;
    list<int> dstA;
    list<int> dstB;
    // input
    scanf("%d", &timeout);
    scanf("%d %d", &NA, &NB);

    int srcHour, srcMin;
    int dstHour, dstMin;
    for (int i = 1; i <= NA; i++)
    {
        scanf("%d:%d", &srcHour, &srcMin);
        scanf("%d:%d", &dstHour, &dstMin);
        srcA.push_back(srcHour * 60 + srcMin);
        dstB.push_back(dstHour * 60 + dstMin + 5);
    }
    for (int i = 1; i <= NB; i++)
    {
        scanf("%d:%d", &srcHour, &srcMin);
        scanf("%d:%d", &dstHour, &dstMin);
        srcB.push_back(srcHour * 60 + srcMin);
        dstA.push_back(dstHour * 60 + dstMin + 5);
    }
    sort(srcA.begin(), srcA.end());
    sort(srcB.begin(), srcB.end());
    dstA.sort();
    dstB.sort();

    // solution
    for (auto timeSrc : srcA)
    {
        for (auto iterDst = dstA.begin(); iterDst != dstA.end(); iterDst++)
        {
            if (*iterDst <= timeSrc)
            {
                NA--;
                dstA.erase(iterDst);
                break;
            }
        }
    }
    for (auto timeSrc : srcB)
    {
        for (auto iterDst = dstB.begin(); iterDst != dstB.end(); iterDst++)
        {
            if (*iterDst <= timeSrc)
            {
                NB--;
                dstB.erase(iterDst);
                break;
            }
        }
    }

    // output
    printf("Case #%d: %d %d\n", caseNumber, NA, NB);

    return 0;
}

void test_case()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        solution(i);
    }
}

int main()
{
    test_case();
    return 0;
}