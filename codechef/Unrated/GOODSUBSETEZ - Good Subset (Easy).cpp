#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int count[32] = {0};

        for (int i = 0; i < N; i++) {
            long long x;
            cin >> x;

            int bit = 0;

            while (x > 1) {
                x = x / 2;
                bit++;
            }

            count[bit]++;
        }

        int ans = 0;

        for (int i = 0; i < 32; i++) {
            ans = max(ans, count[i]);
        }

        cout << ans << endl;
    }

    return 0;
}