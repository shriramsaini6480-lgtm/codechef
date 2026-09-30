#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct SegmentTree {
    int n;
    vector<int> sum;
    vector<bool> clearAll;

    SegmentTree(int size) : n(size), sum(4 * size + 4), clearAll(4 * size + 4) {}

    void clearNode(int node) {
        sum[node] = 0;
        clearAll[node] = true;
    }

    void push(int node) {
        if (clearAll[node]) {
            clearNode(node * 2);
            clearNode(node * 2 + 1);
            clearAll[node] = false;
        }
    }

    void clearRange(int node, int left, int right, int ql, int qr) {
        if (ql > right || qr < left) return;
        if (ql <= left && right <= qr) {
            clearNode(node);
            return;
        }

        push(node);
        int mid = (left + right) / 2;
        clearRange(node * 2, left, mid, ql, qr);
        clearRange(node * 2 + 1, mid + 1, right, ql, qr);
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
    }

    void add(int node, int left, int right, int index, int value) {
        if (left == right) {
            sum[node] = (sum[node] + value) % MOD;
            return;
        }

        push(node);
        int mid = (left + right) / 2;
        if (index <= mid) add(node * 2, left, mid, index, value);
        else add(node * 2 + 1, mid + 1, right, index, value);
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
    }

    int query(int node, int left, int right, int ql, int qr) {
        if (ql > right || qr < left) return 0;
        if (ql <= left && right <= qr) return sum[node];

        push(node);
        int mid = (left + right) / 2;
        return (query(node * 2, left, mid, ql, qr) +
                query(node * 2 + 1, mid + 1, right, ql, qr)) % MOD;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> Q(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> Q[i];
        }

        bool possible = true;

        // The final K - 1 elements must be sorted.
        for (int i = N - K + 2; i <= N; i++) {
            if (Q[i - 1] > Q[i]) {
                possible = false;
            }
        }

        if (!possible) {
            cout << 0 << '\n';
            continue;
        }

        SegmentTree seg(N);
        seg.add(1, 1, N, Q[N - K + 2], 1);

        // Reverse the process, handling outputs from right to left.
        for (int i = N - K + 1; i >= 2; i--) {
            int ways = seg.query(1, 1, N, Q[i] + 1, N);

            // Discard states whose minimum is smaller than Q[i].
            if (Q[i] > 1) {
                seg.clearRange(1, 1, N, 1, Q[i] - 1);
            }

            // There are K - 1 choices for which buffered element arrived.
            seg.add(1, 1, N, Q[i], (long long)ways * (K - 1) % MOD);
        }

        int ways = seg.query(1, 1, N, Q[1] + 1, N);

        long long factorial = 1;
        for (int i = 1; i <= K; i++) {
            factorial = factorial * i % MOD;
        }

        cout << factorial * ways % MOD << '\n';
    }

    return 0;
}