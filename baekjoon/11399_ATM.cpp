#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution() {
  int N;
  vector<int> people;
  cin >> N;

  people.resize(N);
  for(int i = 0; i < N; i++)
  {
    cin >> people[i];
  }
  sort(people.begin(), people.end());

  int sum = 0;
  int current_sum = 0;
  for(int i = 0; i < N; i++)
  {
    current_sum += people[i];
    sum += current_sum;
  }

  cout << sum << "\n";
  
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}