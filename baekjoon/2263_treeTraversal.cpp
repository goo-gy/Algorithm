#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> inOrder;
vector<int> postOrder;


class TreeNode{
public:
  TreeNode *left;
  TreeNode *right;
  int value;
  TreeNode(int value){

  }
};

int div_con(int start, int end) {
    int root = postOrder[end];
    for(int i = 0)
}

int soultion() {
  // input  
  cin >> N;
  inOrder.resize(N);
  postOrder.resize(N);

  for(int i = 0; i < N; i++){
    cin >> inOrder[i];
  }
  for(int i = 0; i < N; i++){
    cin >> postOrder[i];
  }
  // solution
//   TreeNode *root = new TreeNode(postOrder[N-1]);
  div_con(0, N-2);

  // output
  
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}