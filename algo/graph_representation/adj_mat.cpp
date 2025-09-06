#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  size_t v, e;
  cin >> v >> e;

  vector<vector<int>> graph(v, vector<int>(v, 0));

  for (size_t i = 0; i < e; ++i) {
    size_t u, w;
    cin >> u >> w;
    graph[u][w] = 1;
    graph[w][u] = 1; // Assuming undirected graph
  }
}