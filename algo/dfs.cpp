#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dfs_traversal(int start, vector<int> adj[], int n) {
  vector<int> visited(n + 1, 0);
  vector<int> dfs;
  stack<int> st;

  visited[start] = 1;
  st.push(start);
  dfs.push_back(start); // Add start to result immediately

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = 1;
        st.push(neighbor);
        dfs.push_back(neighbor);
      }
    }
  }

  return dfs;
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

  int start;
  cin >> start;

  vector<int> result = dfs_traversal(start, adj, n);

  for (int node : result) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
