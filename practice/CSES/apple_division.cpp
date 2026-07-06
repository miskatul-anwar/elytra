#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

// Recursive function to minimize the difference
ll solve(int idx, const vector<ll> &arr, ll sum1, ll sum2) {
  if (idx == (int)arr.size())
    return abs(sum1 - sum2);

  // Add arr[idx] to group 1
  ll include = solve(idx + 1, arr, sum1 + arr[idx], sum2);

  // Add arr[idx] to group 2
  ll exclude = solve(idx + 1, arr, sum1, sum2 + arr[idx]);

  return min(include, exclude);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ll> arr(n);
  for (ll &i : arr)
    cin >> i;

  ll ans = solve(0, arr, 0, 0);
  cout << ans << '\n';
  return 0;
}
