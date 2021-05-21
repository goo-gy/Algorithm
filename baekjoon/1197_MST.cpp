#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// struct Edge {
//   int weight;
//   int src;
//   int dst;
// };

class Edge{
public:
  int weight;
  int src;
  int dst;
  bool operator < (Edge &ref) {
    return (this->weight < ref.weight);
  }
};



int V, E;
// vector<vector<pair<int, int> > > graph;
vector<Edge> edges;

int solution() {

  cin >> V >> E;
  // graph.resize(V+1);

  for(int i = 0; i < E; i++)
  {
    Edge edge;
    cin >> edge.src >> edge.dst >> edge.weight;
    // graph[src].push_back(make_pair(dst, weight));
    
    edges.push_back(edge);
  }

  // kruskal's
  sort(edges.begin(), edges.end());
  for(int i = 0; i < V; i++){
    cout << edges[i].weight << " " << edges[i].src << " " << edges[i].dst << endl;
  }

  
  
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}