#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long X, Y;
        cin >> X >> Y;

        cout << (X >= 30 * Y ? "YES" : "NO") << '\n';
    }

    return 0;
}