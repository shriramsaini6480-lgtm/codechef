#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (long long &x : A) {
            cin >> x;
        }

        vector<long long> prefix(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            prefix[i + 1] = prefix[i] + A[i];
        }

        vector<long long> suffixMin(N + 1);
        suffixMin[N] = prefix[N];

        for (int i = N - 1; i >= 0; --i) {
            suffixMin[i] = min(prefix[i], suffixMin[i + 1]);
        }

        bool possible = false;

        for (int i = 0; i < N; ++i) {
            bool leftGood = true;

            for (int j = 1; j <= i; ++j) {
                if (prefix[j] < 0) {
                    leftGood = false;
                    break;
                }
            }

            if (leftGood && suffixMin[i + 1] - A[i] >= 0) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}