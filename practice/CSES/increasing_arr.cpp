#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(void) {
  ll n;
  cin >> n;
  vector<ll> vi(n);
  for (ll &i : vi) {
    cin >> i;
  }

  ll steps = 0;

  for (ll i = 1; i < n; i++) {
    if (vi[i - 1] > vi[i]) {
      steps += (vi[i - 1] - vi[i]);
      vi[i] = vi[i - 1];
    }
  }

  cout << steps << '\n';
  return 0;
}