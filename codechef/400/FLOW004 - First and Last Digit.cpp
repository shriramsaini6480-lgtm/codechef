#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int lastDigit = N % 10;

        while (N >= 10) {
            N /= 10;
        }

        int firstDigit = N;
        cout << firstDigit + lastDigit << '\n';
    }

    return 0;
}