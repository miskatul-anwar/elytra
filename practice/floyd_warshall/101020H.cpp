#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

struct Edge {
  int to;
  int w;
};

vector<ll> dijkstra(int src, int n, const vector<vector<Edge>> &g) {
  vector<ll> dist(n + 1, INF);
  dist[src] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  pq.push({0, src});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u])
      continue;
    for (auto &e : g[u]) {
      int v = e.to;
      ll nd = d + e.w;
      if (nd < dist[v]) {
        dist[v] = nd;
        pq.push({nd, v});
      }
    }
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  if (!(cin >> T))
    return 0;
  for (int tc = 1; tc <= T; ++tc) {
    int N, M, F;
    cin >> N >> M >> F;
    vector<vector<Edge>> g(N + 1);
    for (int i = 0; i < M; i++) {
      int X, Y, Z;
      cin >> X >> Y >> Z;
      g[X].push_back({Y, Z});
      g[Y].push_back({X, Z});
    }
    vector<int> friends(F);
    for (int i = 0; i < F; i++)
      cin >> friends[i];
    // specials: 0=start(1), 1..F=friends, F+1=end(N)
    vector<int> specials;
    specials.push_back(1);
    for (int x : friends)
      specials.push_back(x);
    specials.push_back(N);
    int K = (int)specials.size(); // K = F+2

    // run dijkstra from each special
    vector<vector<ll>> spDist(K, vector<ll>(N + 1, INF));
    for (int i = 0; i < K; i++) {
      spDist[i] = dijkstra(specials[i], N, g);
    }

    // build cost matrix between specials
    vector<vector<ll>> cost(K, vector<ll>(K, INF));
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        cost[i][j] = spDist[i][specials[j]];
      }
    }

    // check early unreachable: if any friend unreachable from start or end
    // unreachable from anywhere required, we'll detect later via INF checks.
    int ALL = (1 << F) - 1;
    // dp[mask][u] where u in [0..F] (index in specials, excluding final end
    // index F+1)
    int U = F + 1; // count of indices we allow (start + F friends)
    vector<vector<ll>> dp(1 << F, vector<ll>(U, INF));
    dp[0][0] = 0; // at start, no friends collected

    for (int mask = 0; mask <= ALL; ++mask) {
      for (int u = 0; u < U; ++u) {
        if (dp[mask][u] == INF)
          continue;
        // try go to a friend v (special index 1..F) not yet collected
        for (int v = 1; v <= F; ++v) {
          int bit = v - 1;
          if (mask & (1 << bit))
            continue;
          if (cost[u][v] == INF)
            continue; // cannot move
          int nmask = mask | (1 << bit);
          dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + cost[u][v]);
        }
      }
    }

    ll ans = INF;
    int endIdx = F + 1;
    for (int u = 0; u < U; ++u) {
      if (dp[ALL][u] == INF)
        continue;
      if (cost[u][endIdx] == INF)
        continue;
      ans = min(ans, dp[ALL][u] + cost[u][endIdx]);
    }

    cout << "Case " << tc << ": ";
    if (ans == INF)
      cout << -1;
    else
      cout << ans;
    if (tc < T)
      cout << '\n';
  }
  return 0;
}
