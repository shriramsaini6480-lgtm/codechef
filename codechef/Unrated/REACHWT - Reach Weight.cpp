#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 0)
            cout << (n / 2) * 30 << endl;
        else
            cout << (n / 2) * 30 + 20 << endl;
    }

    return 0;
}