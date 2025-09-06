#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int t;
  string s;

  for (cin >> t; t--;) {
    cin >> s;

    int one = 0, zero = 0, n = s.length();

    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        one++;
      else
        zero++;
    }

    int turn = min(zero, one);

    if (turn == 0 || turn % 2 == 0)
      cout << "NET\n";
    else
      cout << "DA\n";
  }

  return 0;
}
