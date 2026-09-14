#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    map<int, int> countA, countB;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        countA[x]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        countB[x]++;
    }

    bool found = false;

    for (auto x : countB) {
        int number = x.first;

        if (countA[number] < countB[number]) {
            if (found) {
                cout << " ";
            }

            cout << number;
            found = true;
        }
    }

    if (!found) {
        cout << -1;
    }

    return 0;
}