#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<long long> d(n + 2, 0);
        int base = 0;
        for (int i = 1; i < n; i++) {
            d[i] = a[i + 1] - a[i];
            if (d[i] == 0) base++;
        }
        int best = 0;        
        int prefMax = 0;     
        for (int j = 1; j <= n; j++) {
            int gr = 0;
            if (j < n) {
                if (d[j] == 1) gr = 1;
                else if (d[j] == 0) gr = -1;
            }
            best = max(best, prefMax + gr);
                if (j < n) {
                int gl = 0;
                if (d[j] == -1) gl = 1;
                else if (d[j] == 0) gl = -1;
                prefMax = max(prefMax, gl);
            }
        }
        cout << base + best << "\n";
    }
    return 0;
}