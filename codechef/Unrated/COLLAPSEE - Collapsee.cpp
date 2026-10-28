#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long res = a[n - 1] - a[n - 2];
        for (int i = 0; i < n - 2; i++) {
            if (a[i] < 0) res -= a[i];
            else res += a[i];
        }
        cout << res << "\n";
    }
    return 0;
}