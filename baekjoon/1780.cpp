#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<vector<int>> total_paper;
int counts[3];

#define NOT_SET -3
#define MIXED -2

int divide_and_conquer(int row, int col, int size) {
  if(size == 1)
    return total_paper[row][col];
  
  int unit = size/3;
  bool is_set = true;
  int set_number = NOT_SET;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      int the_number = divide_and_conquer(row + i*unit, col + j*unit, unit);
      counts[the_number + 1]++;
      if( (set_number != the_number && set_number != NOT_SET) || the_number == MIXED)
        is_set = false;
      set_number = the_number;
    }
  }
  if(is_set)
  {
    if(size == N)
      counts[set_number + 1] -= 8;
    else
      counts[set_number + 1] -= 9;
    return set_number;
  }
  else
    return MIXED;
}

int solution() {
  cin >> N;
  memset(counts, 0, sizeof(counts));

  total_paper.resize(N);
  for(int i = 0; i < N; i++)
  {
    total_paper[i].resize(N);
    for(int j = 0; j < N; j++)
    {
      cin >> total_paper[i][j];
    }
  }

  if(N == 1)
    counts[total_paper[0][0] + 1]++;
  else
    divide_and_conquer(0, 0, N);
  
  cout << counts[0] << "\n" << counts[1] << "\n" << counts[2] << "\n";
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
  return 0;
}