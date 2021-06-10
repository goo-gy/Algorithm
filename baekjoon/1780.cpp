#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > total_paper;
int minus_count;
int count_zero;
int count_one;

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
      int the_number = divide_and_conquer(i*unit, j*unit, unit);
      switch(the_number)
      {
        case -1:
          minus_count++;
          break;
        case 0:
          count_zero++;
          break;
        case 1:
          count_one++;
          break;
      }
      if( (set_number != the_number && set_number != NOT_SET) || the_number == MIXED)
        is_set = false;
      set_number = the_number;
    }
  }
  if(is_set)
  {
      switch(set_number)
      {
        case -1:
          minus_count -= 8;
          break;
        case 0:
          count_zero -= 8;
          break;
        case 1:
          count_one -= 8;
          break;
      }
      cout << minus_count << "," << count_zero << "," << count_one << "," << size << endl;
    return set_number;
  }
  else
  {
    cout << minus_count << "," << count_zero << "," << count_one << "," << size << endl;
    return MIXED;
  }
}

int solution() {
  int N;
  cin >> N;

  total_paper.resize(N);
  for(int i = 0; i < N; i++)
  {
    total_paper[i].resize(N);
    for(int j = 0; j < N; j++)
    {
      cin >> total_paper[i][j];
    }
  }

  divide_and_conquer(0, 0, N);

  cout << minus_count << "\n" << count_zero << "\n" << count_one << "\n";

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}