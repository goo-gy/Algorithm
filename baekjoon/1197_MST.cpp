#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Edge
{
public:
  int weight;
  int src;
  int dst;
  bool operator<(Edge &ref)
  {
    return (this->weight < ref.weight);
  }
};

int V, E;
vector<Edge> edges;
vector<int> parent_vector;
vector<int> size_vector;

int find_root(int node_number)
{
  while(node_number != parent_vector[node_number])
  {
    node_number = parent_vector[node_number];
  }
  return node_number;
}

void union_graph(int root1, int root2)
{
  if(size_vector[root1] < size_vector[root2])
  {
    parent_vector[root1] = root2;
    size_vector[root2] += size_vector[root1];
  } else
  {
    parent_vector[root2] = root1;
    size_vector[root1] += size_vector[root2];
  }
}

int solution()
{
  // input
  cin >> V >> E;
  size_vector.resize(V + 1);
  parent_vector.resize(V + 1);
  for (int i = 0; i < E; i++)
  {
    Edge edge;
    cin >> edge.src >> edge.dst >> edge.weight;
    edges.push_back(edge);
  }

  // set up
  for (int i = 1; i <= V; i++)
  {
    parent_vector[i] = i;
    size_vector[i] = 1;
  }
  
  // kruskal's
  long long total_cost = 0;
  sort(edges.begin(), edges.end());
  for (int i = 0; i < E; i++)
  {
    int root1 = find_root(edges[i].src);
    int root2 = find_root(edges[i].dst);
    if (root1 != root2)
    {
      union_graph(root1, root2);
      total_cost += edges[i].weight;
    }
  }

  // output
  cout << total_cost << "\n";

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}