#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> use_bracket_max;
vector<long long> use_bracket_min;
vector<long long> not_use_bracket_max;
vector<long long> not_use_bracket_min;

long long cal(long long left, char op, long long right)
{
  switch (op)
  {
  case '+':
    return left + right;
  case '-':
    return left - right;
  case '*':
    return left * right;
  default:
    return 0;
  }
}

int solution()
{
  // input
  int length, N;
  string exp;
  cin >> length;
  cin >> exp;
  N = length / 2;

  vector<char> ops(N);
  vector<int> numbers(N + 1);

  for (int i = 0; i < N; i++)
  {
    numbers[i] = exp[2 * i] - 0x30;
    ops[i] = exp[2 * i + 1];
  }
  numbers[N] = exp[length - 1] - 0x30;

  // solution
  use_bracket_max.resize(N + 1, 0);
  use_bracket_min.resize(N + 1, 0);
  not_use_bracket_max.resize(N + 1, 0);
  not_use_bracket_min.resize(N + 1, 0);

  use_bracket_max[0] = numbers[0];
  use_bracket_min[0] = numbers[0];
  not_use_bracket_max[0] = numbers[0];
  not_use_bracket_min[0] = numbers[0];

  if(N >= 1) {
    use_bracket_max[1] = cal(numbers[0], ops[0], numbers[1]);
    use_bracket_min[1] = use_bracket_max[1];
    not_use_bracket_max[1] = use_bracket_max[1];
    not_use_bracket_min[1] = use_bracket_max[1];
  }
  
  for (int i = 2; i <= N; i++)
  {
    // use_bracket_max
    long long right = cal(numbers[i - 1], ops[i - 1], numbers[i]);
    vector<long long> results;
    results.push_back(cal(use_bracket_max[i - 2], ops[i - 2], right));
    results.push_back(cal(use_bracket_min[i - 2], ops[i - 2], right));
    results.push_back(cal(not_use_bracket_max[i - 2], ops[i - 2], right));
    results.push_back(cal(not_use_bracket_min[i - 2], ops[i - 2], right));
    
    sort(results.begin(), results.end());
    use_bracket_min[i] = results[0];
    use_bracket_max[i] = results[3];

    // not_use_bracket_max
    vector<long long> results_none;
    results_none.push_back(cal(use_bracket_max[i - 1], ops[i - 1], numbers[i]));
    results_none.push_back(cal(use_bracket_min[i - 1], ops[i - 1], numbers[i]));
    results_none.push_back(cal(not_use_bracket_max[i - 1], ops[i - 1], numbers[i]));
    results_none.push_back(cal(not_use_bracket_min[i - 1], ops[i - 1], numbers[i]));

    sort(results_none.begin(), results_none.end());
    not_use_bracket_min[i] = results_none[0];
    not_use_bracket_max[i] = results_none[3];
  }

  // output
  cout << max(use_bracket_max[N], not_use_bracket_max[N]) << "\n";
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
  return 0;
}