#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        string S;
        cin >> N >> K >> S;

        int alarms = 0;
        int i = 0;

        while (i < N) {
            if (S[i] == '1') {
                ++alarms;
                
                i = min(N, i + K + 1);
            } else {
                ++i;
            }
        }

        cout << alarms << '\n';
    }

    return 0;
}