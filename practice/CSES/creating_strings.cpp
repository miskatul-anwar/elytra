#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();

  string s;
  cin >> s;
  set<string> u_perm;
  u_perm.insert(s);
  sort(s.begin(), s.end());

  do {
    u_perm.insert(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << u_perm.size() << '\n';
  for (string s : u_perm) {
    cout << s << '\n';
  }

  return 0;
}