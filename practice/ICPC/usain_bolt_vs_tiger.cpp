#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;

using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  ll t;
  for (cin >> t; t--;) {
    double finish, dist_bolt, tig_acc, bolt_sp;
    cin >> finish >> dist_bolt >> tig_acc >> bolt_sp;
    double tb = finish / bolt_sp;
    double tt = sqrt(2 * (finish + dist_bolt) / tig_acc);
    cout << (tb < tt ? "Bolt\n" : "Tiger\n");
  }

  return 0;
}