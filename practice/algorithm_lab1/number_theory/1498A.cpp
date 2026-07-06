#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static inline int64 sum_digits(int64 x) {
    int64 s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--) {
        long long n;
        cin >> n;
        while (std::gcd(n, sum_digits(n)) == 1) {
            ++n;
        }
        cout << n << '\n';
    }
    return 0;
}
