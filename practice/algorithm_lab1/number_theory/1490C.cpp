#include <iostream>
using namespace std;
using lli = long long int;

lli cube[10005];

void do_cube() {
    for (lli i = 1; i < 10001; i++)
        cube[i] = i * i * i;
}

bool binary_search(lli item) {
    lli left = 1, right = 10000, mid;
    while (left <= right) {

        mid = left + ((right - left) / 2);
        if (item == cube[mid])
            return true;
        else if (item < cube[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return false;
}

int main(void) {
    lli x, t, item;
    bool flag;
    do_cube();

    for (cin >> t; t--;) {

        cin >> x;
        flag = false;

        for (lli j = 1; j < 10001; j++) {

            if (cube[j] >= x)
                break;

            item = x - cube[j];

            if (binary_search(item)) {
                cout << "YES\n";
                flag = true;
                break;
            }
        }

        if (!flag)
            cout << "NO\n";
    }

    return 0;
}
