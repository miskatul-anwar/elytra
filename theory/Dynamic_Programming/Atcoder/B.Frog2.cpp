#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

const int N = 1e5 + 10;
int dp[N], h[N], k;

int sol(int n) {
  if (n == 0) {
    return 0;
  }
  if (dp[n] != -1) {
    return dp[n];
  }

  int cost = INT_MAX;

  for (int i = 1; i <= k; i++)
    if (n - i >= 0)
      cost = min(cost, sol(n - i) + abs(h[n] - h[n - i]));

  return dp[n] = cost;
}

int main() {
  fast_io();
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> h[i];
  cout << sol(n - 1) << '\n';
  return 0;
}