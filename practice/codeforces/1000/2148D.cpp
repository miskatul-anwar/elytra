#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;
using namespace std;

signed main(void) {
  fast_io;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &i : a)
      cin >> i;

    vector<int> p[2];

    for (int i : a)
      p[i % 2].push_back(i);

    ll ans = 0;
    if (p[1].size())
      ans += accumulate(p[0].begin(), p[0].end(), 0LL);

    sort(p[1].rbegin(), p[1].rend());
    int m = p[1].size();

    for (int i = 0; i < (m + 1) / 2; i++)
      ans += p[1][i];

    cout << ans << '\n';
  }
}