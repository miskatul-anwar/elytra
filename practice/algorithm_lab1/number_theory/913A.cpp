#include <iostream>
using ll = long long;
using namespace std;

int main(void) {
    ll n, m;

    cin >> n;
    cin >> m;

    ll res = 1;

    for (int i = 0; i < n; i++) {
        res *= 2;
        if (res > m) {
            cout << m << '\n';
            return 0;
        }
    }

    cout << m % res << '\n';

    return 0;
}
