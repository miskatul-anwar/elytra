#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
const int N = 15e2 + 10;
vi a(N);

int lis(int n) {
  int ans = 1;
  for (int j = 0; j < n; j++) {
    if (a[n] > a[j]) {
      ans = max(ans, lis(j) + 1);
    }
  }
  return ans;
}

int main() {
  fast_io();

  // your code here

  return 0;
}