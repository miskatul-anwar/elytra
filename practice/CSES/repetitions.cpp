#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  string s;
  cin >> s;

  size_t a = 0, c = 0, g = 0, t = 0, m = 0;

  for (char ch : s) {
    if (ch == 'A') {
      a++;
      c = t = g = 0;
      m = max(m, a);
    } else if (ch == 'C') {
      c++;
      a = t = g = 0;
      m = max(m, c);
    } else if (ch == 'G') {
      g++;
      a = t = c = 0;
      m = max(m, g);
    } else {
      t++;
      a = g = c = 0;
      m = max(m, t);
    }
  }

  cout << m << '\n';

  return 0;
}