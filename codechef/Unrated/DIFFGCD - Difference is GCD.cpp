#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long sum = 0;

        for (long long left = 1; left <= N; ) {
            long long quotient = N / left;
            long long right = N / quotient;

            sum += quotient * (right - left + 1);
            left = right + 1;
        }

        cout << sum - N << '\n';
    }

    return 0;
}