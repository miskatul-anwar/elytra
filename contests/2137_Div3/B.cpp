#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int t;

  for (cin >> t; t--;) {
    int n;
    cin >> n;
    vector<int> a(n), q(n);

    for (auto &i : a) {
      cin >> i;
    }

    for (int i = 0; i < n; i++) {
      q[i] = (n + 1) - a[i];
    }

    for (int i = 0; i < n; i++) {
      cout << q[i] << ' ';
    }

    cout << endl;
  }

  return 0;
}
