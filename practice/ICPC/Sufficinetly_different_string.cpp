#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(void) {
  fast_io();
  int t;
  for (cin >> t; t--;) {
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    vector<bool> in_s(26, false);

    for (char c : s)
      in_s[c - 'a'] = true;
    vector<bool> used(26, false);
    string t = "";
    int overlap = 0;

    for (int i = 0; i < n; ++i) {
      bool placed = false;

      for (char c = 'a'; c <= 'z'; ++c) {
        int id = c - 'a';
        if (used[id])
          continue;

        bool is_in_s = in_s[id];

        if (!is_in_s) {
          t.push_back(c);
          used[id] = true;
          placed = true;
          break;
        } else {
          if (overlap < k) {
            t.push_back(c);
            used[id] = true;
            overlap++;
            placed = true;
            break;
          }
        }
      }
      if (!placed) {
        t = "NOPE";
        break;
      }
    }

    cout << t << '\n';
  }

  return 0;
}