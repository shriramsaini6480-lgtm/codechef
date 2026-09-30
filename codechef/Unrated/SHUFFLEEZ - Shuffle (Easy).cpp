#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
        }
        
        long long ans=1;
        
        for (int i=1;i<=k;i++){
            ans=(ans*i) % 998244353;
        }
        
        for (int i=1;i<=n-k;i++){
            ans=(ans*k) % 998244353;
        }
        cout << ans << endl;
    }
return 0;
}