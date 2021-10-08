#include <iostream>
#include <queue>
#include <map>
#include <list>

#define M_I_I_ITER map<int, int>::iterator
#define LI_I_ITER list<int>::iterator

using namespace std;

int N, K;
queue<int> q_inout;
map<int, int> m_customer_in;
list<int> li_seat;

void solution();
void pre_setting();
void input();

int main()
{
    pre_setting();
    input();
    solution();
    return 0;
}

int put_customer(int customer)
{
    if (li_seat.size() == 0)
    {
        li_seat.push_back(0);
        return 0;
    }
    LI_I_ITER iter_insert;
    LI_I_ITER iter = li_seat.begin();
    int max_gap = 0;
    int prev = *iter;
    for (iter++; iter != li_seat.end(); iter++)
    {
        if (*iter - prev > max_gap)
        {
            max_gap = *iter - prev;
            iter_insert = iter;
        }
        prev = *iter;
    }
    int seat_mid;
    if (*li_seat.begin() + N - prev > max_gap)
    {
        int next = *li_seat.begin() + N; 
        max_gap = next - prev;
        seat_mid = ((next + prev) / 2) % N;
        if(seat_mid < prev)
            iter_insert = li_seat.begin();
        else 
            iter_insert = li_seat.end();
    }
    else
    {
        LI_I_ITER iter_insert_front = iter_insert;
        iter_insert_front--;
        seat_mid = (*iter_insert_front + *iter_insert) / 2;
    }
    li_seat.insert(iter_insert, seat_mid);
    return seat_mid;
}

void solution()
{
    for (int i = 0; i < K; i++)
    {
        int customer = q_inout.front();
        q_inout.pop();
        M_I_I_ITER iter_customer = m_customer_in.find(customer);
        if (iter_customer == m_customer_in.end())
        {
            if (li_seat.size() < N)
            {
                int seat_number = put_customer(customer);
                m_customer_in[customer] = seat_number;
                cout << customer << " " << seat_number + 1 << "\n";
            }
        }
        else
        {
            int seat_number = m_customer_in[customer];
            li_seat.remove(seat_number);
            m_customer_in.erase(customer);
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