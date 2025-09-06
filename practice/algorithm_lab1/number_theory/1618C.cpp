#include <cstdint>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>
using namespace std;
using ll = long long;
const ll uplim = (ll)1e19;

int32_t main(void) {
    int n, t;

    for (cin >> t; t--;) {
        cin >> n;
        vector<ll> a(n + 1);

        int x = 0, y = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];

            if (i % 2)
                x = gcd(x, a[i]);
            else
                y = gcd(y, a[i]);
        }

        int f1 = 0;

        for (int i = 2; i <= n; i += 2) {
            if (a[i] % x == 0) {
                f1 = 1;
                break;
            }
        }

        if (f1 == 0) {
            cout << x << '\n';
            continue;
        }

        int f2 = 0;

        for (int i = 1; i <= n; i += 2) {
            if (a[i] % y == 0) {
                f2 = 1;
                break;
            }
        }

        if (f2 == 0) {
            cout << y << '\n';
            continue;
        }

        cout << 0 << '\n';
    }

    return 0;
}
