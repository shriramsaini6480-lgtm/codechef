#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        vector<bool> present(n + 2, false);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            if (a[i] <= n) present[a[i]] = true;
        }
        long long m = 0;
        while (present[m]) m++;

        long long cnt = 0;
        for (int x : a) if (x > m) cnt++;

        long long finalSum = m * (m - 1) / 2 + cnt * (m + 1);
        long long moves = sum - finalSum;

        puts(moves % 2 ? "Alice" : "Bob");
    }
    return 0;
}