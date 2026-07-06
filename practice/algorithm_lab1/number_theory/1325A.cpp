#include <iostream>
using namespace std;
using ll = long long;

#define fast_io                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int main(void) {
    fast_io;
    int n, t;

    for (cin >> t; t--;) {
        cin >> n;
        cout << 1 << ' ' << n - 1 << '\n';
    }

    return 0;
}
