#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    // Sort array in ascending order
    sort(A.begin(), A.end());
    
    long long max_val = 0;
    long long S_B = 0; // Sum of Blue elements (smallest elements)
    
    // Loop through all split points:
    // First 'i' elements go to Blue, remaining go to Red.
    for (int i = 1; i < N; i++) {
        S_B += A[i - 1];                  // Add current element to Blue sum
        long long S_R = total_sum - S_B;  // Remaining sum goes to Red
        
        long long C_B = i;                // Number of Blue elements
        long long C_R = N - i;            // Number of Red elements
        
        long long current_val = S_R * C_B + S_B * C_R;
        max_val = max(max_val, current_val);
    }
    
    cout << max_val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}