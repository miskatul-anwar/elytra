#include <iostream>

using namespace std;
int main(void) {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int sa, sb;
    cin >> sa >> sb;

    int i, j;
    for (int c = 0; c < n; ++c)
      if (s[c] == 'A')
        i = c;
      else if (s[c] == 'B')
        j = c;

    bool collision = false;
    while (j >= 0 && i < n) {
      if (i == j) {
        collision = true;
      }
      i += sa, j -= sb;
    }

    cout << (collision ? "unsafe\n" : "safe\n");
  }

  return 0;
}