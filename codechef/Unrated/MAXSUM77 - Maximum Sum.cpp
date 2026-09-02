#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        int A[N];

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int len = N - K;
        int ans = 0;

        for (int i = 0; i <= K; i++) {
            int sum = 0;

            for (int j = i; j < i + len; j++) {
                sum += A[j];
            }

            ans = max(ans, sum);
        }

        cout << ans << endl;
    }

    return 0;
}