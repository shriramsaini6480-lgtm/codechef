#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        if (N == 1)
            cout << 1 << endl;
        else
            cout << 3 * (N / 2) + 1 << endl;
    }

    return 0;
}