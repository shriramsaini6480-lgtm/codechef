#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> C(N);
        for (int &cost : C) {
            cin >> cost;
        }

        int ans = INT_MAX;

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                bool coversLeft = i - K <= 0;
                bool coversRight = j + K >= N - 1;
                bool noGap = j - i <= 2 * K + 1;

                if (coversLeft && coversRight && noGap) {
                    ans = min(ans, C[i] + C[j]);
                }
            }
        }

        if (ans == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }

    return 0;
}