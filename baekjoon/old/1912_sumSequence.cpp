#include <iostream>
#include <vector>
using namespace std;

int read_input();
int print_output(int result);
int solution();
int N;
vector<int> numbers;

int main()
{
    read_input();
    int result = solution();
    print_output(result);
    return 0;
}

int find_max_sum(int start, int end)
{
    if(start == end)
        return numbers[start];
    
    int middle = (start + end)/2;
    // get middle
    int left = middle;
    int right = middle + 1;
    int current_sum = numbers[left] + numbers[right];
    int max_middle = current_sum;
    while(right < end) // stretch right
    {
        right++;
        current_sum += numbers[right];
        if(current_sum > max_middle)
            max_middle = current_sum;
    }
    current_sum = max_middle;
    while(left > start) // stretch left
    {
        left--;
        current_sum += numbers[left];
        if(current_sum > max_middle)
            max_middle = current_sum;
    }
    // max left, max right
    int max_side = max(find_max_sum(start, middle), find_max_sum(middle + 1, end));
    
    return max(max_middle, max_side);
}

int solution()
{
    return find_max_sum(0, N-1);
}

int read_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    numbers.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    return 0;
}

int print_output(int result)
{
    cout << result << endl;
    return 0;
}