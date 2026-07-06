#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#define INF 1000000000
using namespace std;

using vi = vector<int>;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int n, x;
  cin >> n >> x;
  vi coins(n);
  for (int &c : coins) {
    cin >> c;
  }

  vi dp(x + 1, 1e9);
  dp[0] = 0;

  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (coins[j] <= i) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  cout << (dp[x] < 1e9 ? dp[x] : -1) << endl;
  return 0;
}