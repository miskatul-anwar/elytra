#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  size_t v, e;
  cin >> v >> e;

  vector<vector<int>> adj_list(v);

  for (size_t i = 0; i < e; ++i) {
    size_t u, w;
    cin >> u >> w;
    adj_list[u].push_back(w);
    adj_list[w].push_back(u); // Assuming undirected graph
  }
}