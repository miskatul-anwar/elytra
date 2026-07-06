#include <iostream>
using namespace std;
using ll = long long;

int main(void) {
    int t, x;

    for (cin >> t; t--;) {
        cin >> x;

        for (int y = 1;; y *= 2) {
            if (((x ^ y) > 0) && ((x & y) > 0)) {
                cout << y << endl;
                break;
            } else if (((x ^ (y + 1)) > 0) && ((x & (y + 1)) > 0)) {
                cout << (y + 1) << endl;
                break;
            }
        }
    }
}
