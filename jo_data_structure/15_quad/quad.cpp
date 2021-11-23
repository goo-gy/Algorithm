#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

enum { IMG = 0, QTS };

int K, N;
string str_QTS;
vector<vector<int>> v_image;


int get_mode()
{
    string str_mode;
    cin >> str_mode;
    if (str_mode == "QTS")
        return QTS;
    else if (str_mode == "IMG")
        return IMG;
    return -1;
}

void set_image_size(int size)
{
    v_image.resize(size);
    for (int i = 0; i < size; i++)
    {
        v_image[i].resize(size);
    }
}

void get_image()
{
    for (int i = 0; i < N; i++)
    {
        string image_row;
        cin >> image_row;
        for (int j = 0; j < N; j++)
        {
            v_image[i][j] = image_row[j] - '0';
        }
    }
}

void print_QTS(int size, int row_s, int col_s)
{
    if (size < 1)
        return;
    int initial = v_image[row_s][col_s];
    bool mixed = false;
    for (int row = row_s; row < row_s + size; row++)
    {
        for (int col = col_s; col < col_s + size; col++)
        {
            if (v_image[row][col] != initial)
            {
                mixed = true;
                break;
            }
        }
    }
    if (mixed)
    {
        cout << "(";
        int next_size = size / 2;
        print_QTS(next_size, row_s, col_s + next_size);
        print_QTS(next_size, row_s, col_s);
        print_QTS(next_size, row_s + next_size, col_s);
        print_QTS(next_size, row_s + next_size, col_s + next_size);
        cout << ")";
    }
    else
        cout << initial;
}

void QTS_to_image()
{
    cin >> str_QTS;
    stack<tuple<int, int, int>> s_range;
    s_range.push({N, 0, 0});
    int QTS_index = 0;
    while (!s_range.empty())
    {
        tuple<int, int, int> range = s_range.top();
        s_range.pop();
        int size = get<0>(range);
        int row_s = get<1>(range);
        int col_s = get<2>(range);

        int next_size = size / 2;
        switch (str_QTS[QTS_index])
        {
        case '(':
            s_range.push(range);
            s_range.push({next_size, row_s + next_size, col_s + next_size});
            s_range.push({next_size, row_s + next_size, col_s});
            s_range.push({next_size, row_s, col_s});
            s_range.push({next_size, row_s, col_s + next_size});
            break;
        case ')':
            break;
        default:
            int pixel = str_QTS[QTS_index] - '0';
            for (int row = row_s; row < row_s + size; row++)
            {
                for (int col = col_s; col < col_s + size; col++)
                {
                    v_image[row][col] = pixel;
                }
            }
            break;
        }
        QTS_index++;
    }
}

void print_image()
{
    for (auto image_row : v_image)
    {
        for (auto pixel : image_row)
        {
            cout << pixel;
        }
        cout << "\n";
    }
}

void solution()
{
    cin >> K;
    N = 1 << K;
    int mode = get_mode();
    set_image_size(N);
    switch (mode)
    {
    case IMG:
        get_image();
        print_QTS(N, 0, 0);
        break;
    case QTS:
        QTS_to_image();
        print_image();
        break;
    default:
        break;
    }
}

void pre_setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    pre_setting();
    solution();
    return 0;
}