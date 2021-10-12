#include <iostream>
#include <queue>
#include <map>
#include <list>

#define M_I_I_ITER map<int, int>::iterator

using namespace std;

int N, K;
queue<int> q_inout;
map<int, int> m_cust_seat;
map<int, int> m_seat_cust;
list<pair<int, int>> li_answer;

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

int put_customer(int customer)
{
    if (m_seat_cust.size() == 0)
    {
        m_seat_cust[0] = customer;
        return 0;
    }
    M_I_I_ITER iter = m_seat_cust.begin();
    int prev = iter->first;
    int gap, seat, max_seat, max_gap = 0;
    for (iter++; iter != m_seat_cust.end(); iter++)
    {
        gap = iter->first - prev;
        seat = (iter->first + prev) / 2;
        if (gap > max_gap)
        {
            max_gap = gap;
            max_seat = seat;
        }
        prev = iter->first;
    }
    gap = m_seat_cust.begin()->first + N - prev;
    seat = ((m_seat_cust.begin()->first + N + prev) / 2) % N;
    if (gap > max_gap)
    {
        max_gap = gap;
        max_seat = seat;
    };
    m_seat_cust[max_seat] = customer;
    return max_seat;
}

void solution()
{
    for (int i = 0; i < K; i++)
    {
        int customer = q_inout.front();
        q_inout.pop();
        M_I_I_ITER iter_customer = m_cust_seat.find(customer);
        if (iter_customer == m_cust_seat.end())
        {
            if (m_seat_cust.size() < N)
            {
                int seat = put_customer(customer);
                m_cust_seat[customer] = seat;
                li_answer.push_back(make_pair(customer, seat + 1));
            }
        }
        else
        {
            int seat = m_cust_seat[customer];
            m_seat_cust.erase(seat);
            m_cust_seat.erase(customer);
        }
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
    for (int i = 0; i < K; i++)
    {
        int customer;
        cin >> customer;
        q_inout.push(customer);
    }
}

void output()
{
    for (auto answer : li_answer)
    {
        cout << answer.first << " " << answer.second << "\n";
    }
}