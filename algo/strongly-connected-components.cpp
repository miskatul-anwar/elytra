/* TODO: Implement the algorithm for strongly connected components. */
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FASTIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

const int INF = 1e9;
const long long LINF = 1e18;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-9;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

vector<bool> visited;
vector<vector<int>> adj_list;

void dfs(int v) {
  visited[v] = true;
  for (int u : adj_list[v])
    if (!visited[u])
      dfs(u);
}

int main() {
  FASTIO;

  // Your code goes here

  return 0;
}