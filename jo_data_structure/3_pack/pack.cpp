#include <vector>
#include <iostream>

using namespace std;
#define INF 1234567890

pair<int, int> boxes[3];
int a1, a2, b1, b2, c1, c2;

int solution();
void pre_setting();
void read_input();
void write_output(const int answer);

int main()
{
    pre_setting();
    read_input();
    int result = solution();
    write_output(result);
    return 0;
}

int pack_two(int a_sum, int a_com, int b_sum, int b_com)
{
    int big_1 = a_sum + b_sum;
    int big_2 = max(a_com, b_com);

    int small_1 = a_com < b_com ? a_sum : b_sum;
    int small_2 = abs(a_com - b_com);

    return big_1 * big_1 + big_2 * big_2;
}

int add_c(int big_1, int big_2, int small_1, int small_2)
{
    if (min(small_1, small_2) >= min(c1, c2) && max(small_1, small_2) >= max(c1, c2))
    {
        return big_1 * big_1 + big_2 * big_2;
    }

    int minimum_cost = INF;
    if (small_1 && small_2)
    {
        // case small_1 - c1
        int extend_1, extend_2;
        extend_1 = (c1 - small_1) < 0 ? 0 : (c1 - small_1);
        extend_2 = (c2 - small_2) < 0 ? 0 : (c2 - small_2);
        minimum_cost = min(minimum_cost, (big_1 + extend_1) * (big_1 + extend_1) + (big_2 + extend_2) * (big_2 + extend_2));

        // case small_1 - c2
        extend_1 = (c2 - small_1) < 0 ? 0 : (c2 - small_1);
        extend_2 = (c1 - small_2) < 0 ? 0 : (c1 - small_2);
        minimum_cost = min(minimum_cost, (big_1 + extend_1) * (big_1 + extend_1) + (big_2 + extend_2) * (big_2 + extend_2));
    }

    // other
    minimum_cost = min(minimum_cost, pack_two(big_1, big_2, c1, c2));
    minimum_cost = min(minimum_cost, pack_two(big_1, big_2, c2, c1));
    minimum_cost = min(minimum_cost, pack_two(big_2, big_1, c1, c2));
    minimum_cost = min(minimum_cost, pack_two(big_2, big_1, c2, c1));
    return minimum_cost;
}

int pack_three(int a_sum, int a_com, int b_sum, int b_com)
{
    int big_1 = a_sum + b_sum;
    int big_2 = max(a_com, b_com);

    int small_1 = a_com < b_com ? a_sum : b_sum;
    int small_2 = abs(a_com - b_com);

    return add_c(big_1, big_2, small_1, small_2);
}

int solution()
{
    int minimum_cost = INF;
    minimum_cost = min(minimum_cost, pack_three(a1, a2, b1, b2));
    minimum_cost = min(minimum_cost, pack_three(a1, a2, b2, b1));
    minimum_cost = min(minimum_cost, pack_three(a2, a1, b1, b2));
    minimum_cost = min(minimum_cost, pack_three(a2, a1, b2, b1));
    return minimum_cost;
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input()
{
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
}

void write_output(const int answer)
{
    cout << answer;
}
