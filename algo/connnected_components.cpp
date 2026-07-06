#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// DFS function using stack (iterative)
void dfs(int start, vector<int> adj[], vector<int> &visited) {
  stack<int> st;
  visited[start] = 1;
  st.push(start);

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = 1;
        st.push(neighbor);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> adj[n + 1]; // 1-indexed

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected graph
  }

  vector<int> visited(n + 1, 0);
  int component_count = 0;

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      component_count++;
      dfs(i, adj, visited);
    }
  }

  cout << "Number of connected components: " << component_count << endl;

  return 0;
}
