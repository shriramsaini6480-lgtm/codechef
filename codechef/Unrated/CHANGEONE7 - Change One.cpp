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
        vector<int> A(N);

        for (int &x : A) cin >> x;
        sort(A.begin(), A.end());

        cout << min(A[N - 1] - A[1], A[N - 2] - A[0]) << '\n';
    }

    return 0;
}