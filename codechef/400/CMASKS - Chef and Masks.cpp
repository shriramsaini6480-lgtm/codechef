#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            int x, y;
            cin >> x >> y;
            
            int cost_disposable = 100 * x;
            int cost_cloth = 10 * y;
            
            if (cost_cloth <= cost_disposable) {
                cout << "CLOTH\n";
            } else {
                cout << "DISPOSABLE\n";
            }
        }
    }
    return 0;
}