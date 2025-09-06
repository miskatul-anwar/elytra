#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    switch (x % 4) {
    case 1:
        cout << "0 A\n";
        break;
    case 2:
        cout << "1 B\n";
        break;
    case 3:
        cout << "2 A\n";
        break;
    case 0:
        cout << "1 A\n";
        break;
    }

    return 0;
}
