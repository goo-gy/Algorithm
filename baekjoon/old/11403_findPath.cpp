#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
int map[100][100];

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int solution()
{
    for (int middle = 0; middle < N; middle++)
    {
        for (int from = 0; from < N; from++)
        {
            if (middle == from)
                continue;
            for (int to = 0; to < N; to++)
            {
                if (map[from][middle] == 1 && map[middle][to] == 1)
                {
                    map[from][to] = 1;
                }
            }
        }
    }
    return 0;
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    return 0;
}

int print_output(int result)
{
    for (int from = 0; from < N; from++)
    {
        for (int to = 0; to < N; to++)
        {
            cout << map[from][to] << " ";
        }
        cout << "\n";
    }
    return 0;
}