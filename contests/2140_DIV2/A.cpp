#include <iostream>
#include <string>
using namespace std;
int main(void) {
  int t;

  for (cin >> t; t--;) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int zeros = 0, turn = 0;

    for (char c : s) {
      if (c == '0')
        zeros++;
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == '0' && i >= zeros) {
        turn++;
      }
    }

    cout << turn << endl;
  }
}
