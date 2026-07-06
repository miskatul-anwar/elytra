#include <deque>
#include <iostream>
#include <map>
#include <string>
#define pb push_back
#define pf push_front
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  string s;
  cin >> s;
  map<char, int> freq;

  for (char c : s) {
    freq[c]++;
  }

  int odd_c = 0;
  for (auto key : freq) {
    if (key.second % 2 != 0) {
      odd_c++;
    }
  }

  if (odd_c > 1) {
    cout << "NO SOLUTION\n";
  } else {
    deque<char> s_deq;

    for (auto key : freq) {
      char c = key.first;
      int f = key.second;

      if (f % 2 != 0) {
        for (int i = 1; i <= f; i++) {
          s_deq.pb(c);
        }
      }
    }

    for (auto key : freq) {
      char c = key.first;
      int f = key.second;

      if (f % 2 == 0) {
        for (int i = 1; i <= f / 2; i++) {
          s_deq.pb(c);
        }

        for (int i = 1; i <= f / 2; i++) {
          s_deq.pf(c);
        }
      }
    }

    string s;

    for (auto i : s_deq) {
      s += i;
    }

    cout << s << '\n';
  }

  return 0;
}