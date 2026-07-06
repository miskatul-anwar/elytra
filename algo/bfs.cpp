#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
using namespace std;

// BFS traversal function for 1-based indexing

vector<int> bfs_of_graph(int V, vector<int> adj[], int start_node) {
  vector<int> vis(V + 1, 0); // +1 to handle 1-based indexing
  vector<int> bfs;
  queue<int> q;

  vis[start_node] = 1;
  q.push(start_node);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    bfs.push_back(node);

    for (auto it : adj[node]) {
      if (!vis[it]) {
        vis[it] = 1;
        q.push(it);
      }
    }
  }

  return bfs;
}

int main() {
  int n, m;
  cin >> n >> m; // n = number of nodes (1-based), m = number of edges

  vector<int> adj[n + 1]; // +1 for 1-based indexing

  // Reading the edges
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a); // Undirected graph
  }

  int start_node = 1; // Start BFS from node 1 (1-based)

  vector<int> ans = bfs_of_graph(n, adj, start_node);

  // Print BFS traversal
  for (auto it : ans) {
    cout << it << ' ';
  }

  cout << '\n';
  return 0;
}
