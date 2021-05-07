#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct edge {
  int u_; // source vertex
  int v_; // destination vertex
  int weight_;

  edge() : u_(-1), v_(-1), weight_(-1) {}
  edge(int u, int v, int weight) : u_(u), v_(v), weight_(weight) {}
};

bool bellman_ford(int n, int source, const vector<edge>& edges)
{
  // initialize the graph
  vector<int> distances(n, numeric_limits<int>::max());
  distances[source] = 0;
  // relax the edges repeatedly
  for (int i = 0; i < n - 1; i++)
    for (size_t j = 0, je = edges.size(); j < je; j++) {
      const edge& e = edges[j];
      if (distances[e.u_] + e.weight_ < distances[e.v_])
        distances[e.v_] = distances[e.u_] + e.weight_;
    }
  // check for negative-weight cycles
  for (size_t i = 0, ie = edges.size(); i < ie; i++) {
    const edge& e = edges[i];
    if (distances[e.u_] + e.weight_ < distances[e.v_])
      return true; // the graph contains a negative-weight cycle
  }
  return false;
}

int main()
{
  while (true) {
    int n;
    cin >> n;
    if (!n)
      break;
    int m;
    cin >> m;
    vector<edge> edges(n + m + 1);
    int i;
    for (i = 0; i < n + 1; i++)
      edges[i] = edge(n + 1, i, 0);
        // edges from specical vertex (n + 1) to any other vertex
    for ( ; i < n + m + 1; i++) {
      int j, k, c;
      string op;
      cin >> j >> k >> op >> c;
      k += j; j--;
      if (op == "gt") {
        swap(j, k);
        c++; c = -c;
      }
      else
        c--;
      edges[i] = edge(j, k, c);
    }
    // Bellman-Ford's shortest path algorithm should start
    // from the special vertex (n + 1)
    cout << ((bellman_ford(n + 2, n + 1, edges)) ?
      "successful conspiracy\n" : "lamentable kingdom\n");
  }
  return 0;
}
