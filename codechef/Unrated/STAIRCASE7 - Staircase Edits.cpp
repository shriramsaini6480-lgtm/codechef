#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        unordered_map<int, int> frequency;
        int maxFrequency = 0;

        for (int i = 1; i <= N; ++i) {
            int value;
            cin >> value;

            int key = value - i;
            int currentFrequency = ++frequency[key];

            if (currentFrequency > maxFrequency) {
                maxFrequency = currentFrequency;
            }
        }

        cout << N - maxFrequency << '\n';
    }

    return 0;
}