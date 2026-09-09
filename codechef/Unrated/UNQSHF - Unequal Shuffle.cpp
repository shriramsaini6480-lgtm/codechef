#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
 while (T--) {
        int N;
        string A, B;
        cin >> N >> A >> B;
        int totalA = 0;
        for (char ch : A) {
            if (ch == 'a') totalA++;
        }
for (char ch : B) {
            if (ch == 'a') totalA++;
        }
if (totalA == N)
            cout << "YES\n";
            else
            cout << "NO\n";
    }


}