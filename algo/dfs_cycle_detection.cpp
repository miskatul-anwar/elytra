#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool dfs(int start, vector<int> graph[], int v) {
  vector<int> visited(v + 1, 0);
  stack<int> st;
  visited[start] = 1;
  st.push(start);

  while (!st.empty()) {
    int top = st.top();
    st.pop();

    for (int neighbour : graph[top]) {
      if (visited[neighbour]) {
        return true;
      } else {
        visited[neighbour] = 1;
        st.push(neighbour);
      }
    }
  }

  return false;
}

int main(void) {

  int v, e;
  cin >> v >> e;
  vector<int> graph[v + 1];

  while (e--) {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  if (dfs(1, graph, v)) {
    cout << "Yes, Cycle detected!" << '\n';
  } else {
    cout << "No, Cycle not detected!" << '\n';
  }

  return 0;
}
