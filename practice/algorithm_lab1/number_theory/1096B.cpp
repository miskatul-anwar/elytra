#include <iostream>
#include <string>

#define fast_io                                                                \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);

using namespace std;
using cll = const long long;
using ll = long long;

cll mod = 998244353;

int main(void) {
  fast_io;
  int n;
  string s;

  cin >> n;
  cin >> s;

  ll l = 1;
  while (l < n && s[l] == s[0])
    ++l;

  ll r = 1;
  while (r < n && s[n - 1 - r] == s[n - 1])
    ++r;

  ll ans;
  if (s[0] == s[n - 1]) {
    ans = ((l + 1) % mod) * ((r + 1) % mod) % mod;
  } else {
    ans = (l + r + 1) % mod;
  }

  cout << ans % mod << '\n';

  return 0;
}
