#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int N = 1e6 + 10;
static ll dp[N];

ll solve(ll n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 1;

  if (dp[n] != -1)
    return dp[n];

  dp[n] = 0;
  for (int i = 1; i <= 6; ++i) {
    if (n - i >= 0)
      dp[n] = (dp[n] + solve(n - i)) % mod;
  }

  return dp[n];
}

int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  cout << solve(n) << '\n';
  return 0;
}
