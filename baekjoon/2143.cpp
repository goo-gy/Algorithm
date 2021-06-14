#include <iostream>
#include <vector>
using namespace std;

int targetNumber;
int N, M;
vector<int> A, B;

int solution() {
  // input
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> B[i];
  } 
  
  // solution
  for(int i = 0; i < N; i++)
  {
    for(int j = i; j < N; j++)
    {
      
    }
  }
  
  
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
  return 0;
}