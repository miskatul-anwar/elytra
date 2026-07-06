#include <algorithm>
#include <cstddef>
#include <cstring>
#include <vector>
using namespace std;

size_t n;
vector<bool> visited;
vector<vector<int>> adj_list;
vector<int> topo_sort;

void dfs(int v) {
  visited[v] = true;

  for (int u : adj_list[v])
    if (!visited[u])
      dfs(u);

  topo_sort.push_back(v);
}

void topological_sort() {
  visited.assign(n, false);
  topo_sort.clear();

  for (int i = 0; i < n; ++i)
    if (!visited[i])
      dfs(i);

  reverse(topo_sort.begin(), topo_sort.end());
}

int main(void) {}