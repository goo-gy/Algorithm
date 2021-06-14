#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
vector<tuple<short, short, short> > edges;
vector<short> parent_links;
vector<short> sizes;


short find(short node) {
    if(node == parent_links[node])
        return node;
    parent_links[node] = find(parent_links[node]);
    return parent_links[node];
}

int union_tree(short root1, short root2) {
    if(sizes[root1] < sizes[root2])
    {
        parent_links[root1] = root2;
        sizes[root2] += sizes[root1];
    } else
    {
        parent_links[root2] = root1;
        sizes[root1] += sizes[root2];
    }
}

int solution()
{
  cin >> N >> M;
  
  parent_links.resize(N);
  sizes.resize(N, 0);
  for(int i = 0; i < N; i++)
  {
    parent_links[i] = i;
  }
  for(int i = 0; i < M; i++)
  {
    short src, dst, weight;
    cin >> src >> dst >> weight;
    edges.push_back(make_tuple(weight, src, dst));
  }
  sort(edges.begin(), edges.end());

  short max_weight = 0;
  int total = 0;
  for(int i = 0; i < M; i++)
  {
      short weight = get<0>(edges[i]);
      short src_root = find(get<1>(edges[i]));
      short dst_root = find(get<2>(edges[i]));
      if(src_root != dst_root)
      {
          union_tree(src_root, dst_root);
          max_weight = max(max_weight, weight);
          total += weight;
      }
  }
  
  cout << total - max_weight << "\n";
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}