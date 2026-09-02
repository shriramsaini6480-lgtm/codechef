#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long a[200005];

        for (int i = 0; i < N; i++) {
            cin >> a[i];

            if (i % 2 == 1) {
                a[i] = -a[i];
            }
        }

        long long ans = abs(a[0]);

        for (int i = 1; i < N; i++) {
            ans += abs(a[i] - a[i - 1]);
        }

        ans += abs(a[N - 1]);

        cout << ans / 2 << endl;
    }

    return 0;
}