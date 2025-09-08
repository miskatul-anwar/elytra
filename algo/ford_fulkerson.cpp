#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// DFS to find an augmenting path from source to sink
bool dfs(int source, int sink, vector<vector<int>> &capacity,
         vector<vector<int>> &adj, vector<int> &parent) {
  int n = adj.size();
  vector<bool> visited(n, false);
  stack<int> st;

  st.push(source);
  visited[source] = true;
  parent[source] = -1;

  while (!st.empty()) {
    int u = st.top();
    st.pop();

    for (int v : adj[u]) {
      if (!visited[v] && capacity[u][v] > 0) {
        visited[v] = true;
        parent[v] = u;
        if (v == sink)
          return true;
        st.push(v);
      }
    }
  }

  return false;
}

// Ford-Fulkerson algorithm using DFS
int ford_fulkerson(int n, int source, int sink, vector<vector<int>> &capacity,
                   vector<vector<int>> &adj) {
  vector<int> parent(n);
  int max_flow = 0;

  while (dfs(source, sink, capacity, adj, parent)) {
    // Find the bottleneck capacity in the found path
    int flow = INT_MAX;
    int v = sink;
    while (v != source) {
      int u = parent[v];
      flow = min(flow, capacity[u][v]);
      v = u;
    }

    // Update residual capacities
    v = sink;
    while (v != source) {
      int u = parent[v];
      capacity[u][v] -= flow;
      capacity[v][u] += flow; // Add reverse flow
      v = u;
    }

    max_flow += flow;
  }

  return max_flow;
}

int main() {
  int n, m;
  cin >> n >> m;

  // Capacity and adjacency list
  vector<vector<int>> capacity(n, vector<int>(n, 0));
  vector<vector<int>> adj(n);

  for (int i = 0; i < m; ++i) {
    int u, v, cap;
    cin >> u >> v >> cap;
    capacity[u][v] = cap; // directed edge u -> v with capacity
    adj[u].push_back(v);
    adj[v].push_back(u); // Add reverse edge for residual graph
  }

  int source, sink;
  cin >> source >> sink;

  int maxFlow = ford_fulkerson(n, source, sink, capacity, adj);
  cout << "Maximum Flow: " << maxFlow << endl;

  return 0;
}
