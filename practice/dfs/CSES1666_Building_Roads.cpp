#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int n, vector<int> adj[]) {}

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1, vector(n + 1, 0));
  vector<vector<int>> visited(n + 1, vector(n + 1, 0));

  while (m--) {
    int a, b;
    cin >> a >> b;

    adj[a][b] = 1;
    adj[b][a] = 1;
  }

  int cnt = 0;
  vector<pair<int, int>> ans;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (adj[i][j] != 1 && visited[i][j] == 0 && visited[j][i] == 0) {
        visited[i][j] = 1;
        visited[j][i] = 1;
        ans.push_back({i, j});
        cnt++;
      }
    }
  }

  cout << cnt << '\n';
  for (auto it : ans) {
    cout << it.first << ' ' << it.second << '\n';
  }

  return 0;
}
