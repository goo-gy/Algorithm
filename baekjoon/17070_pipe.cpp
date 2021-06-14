#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
vector<vector<int>> maps;
int count = 0;

// 0 - 가로
// 1 - 세로
// 2 - 대각

bool check_valid(int row, int col) {
    if(row <= N && col <= N && maps[row][col] == 0)
        return true;
    return false;
}

void DFS(int row, int col, int direction) // row, col, direction
{
    if(!check_valid(row, col))
        return;
    
    if(row == N && col == N)
        count++;
    
    
    switch(direction) {
        case 0:
            if(check_valid(row, col+1))
                DFS(row, col+1, 0);
            if(check_valid(row, col+1) && check_valid(row+1, col) && check_valid(row+1, col+1))
                DFS(row+1, col+1, 2);
            break;
        case 1:
            if(check_valid(row+1, col))
                DFS(row+1, col, 1);
            if(check_valid(row, col+1) && check_valid(row+1, col) && check_valid(row+1, col+1))
                DFS(row+1, col+1, 2);
            break;
        case 2:
            if(check_valid(row, col+1))
                DFS(row, col+1, 0);
            if(check_valid(row+1, col))
                DFS(row+1, col, 1);
            if(check_valid(row, col+1) && check_valid(row+1, col) && check_valid(row+1, col+1))
                DFS(row+1, col+1, 2);
            break;
    }
}

int solution() {
  // input
  cin >> N;
  maps.resize(N+1);

  for(int row = 1; row <= N; row++)
  {
    maps[row].resize(N+1);
    for(int col = 1; col <= N; col++)
    {
      cin >> maps[row][col];
    }
  }

  // solution
  DFS(1, 2, 0);
  
  // output
  cout << count << "\n";
  
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}