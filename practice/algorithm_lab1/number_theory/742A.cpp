#include <cmath>
#include <cstdint>
#include <iostream>
using namespace std;
using ll = int64_t;

int main(int argc, char *argv[]) {
    ll n;
    cin >> n;

    switch (n % 4) {

    case 0:
        if (n == 0) {
            cout << '1' << '\n';
        } else {
            cout << '6' << '\n';
        }

        break;

    case 1:
        cout << '8' << '\n';

        break;

    case 2:
        cout << '4' << '\n';

        break;

    case 3:
        cout << '2' << '\n';

        break;
    }

    return 0;
}
