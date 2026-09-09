#include <iostream>
using namespace std;

int main() {
int T;
cin >> T;
    while (T--) {
    int X, Y;
    cin >> X >> Y;
    for (int days = 1; days <= 201; days++) {
    bool possible = false;
    for (int totalGPUs = 1; totalGPUs <= days; totalGPUs++) {
    int earned = 0;
    for (int day = 1; day <= days; day++) {
    int gpus = min(day, totalGPUs);
    earned += Y * gpus * gpus;
    }

        int spent = totalGPUs * X;
        if (earned > spent) {
        possible = true;
            break;
    }
 }
if (possible) {
    cout << days << '\n';
        break;
            }
        }
    }

}