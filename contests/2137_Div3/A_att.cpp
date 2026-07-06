#include <iostream>
using namespace std;

int main(void) {
  int t;
  cin >> t;

  while (t--) {
    int k, x;
    cin >> k >> x;

    for (int i = 1; i <= 1000000;
         i++) { // Allow large range to guarantee a solution
      int tmp = i;

      for (int j = 0; j < k; j++) {
        if (tmp % 2 == 0) {
          tmp /= 2;
        } else {
          tmp = 3 * tmp + 1;
        }
      }

      if (tmp == x) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}
