#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    map<int ,int> freq;
	    
	    for (int i=0;i<n;i++){
	        int k=a[i] - i;
	        freq[k]++;
	    }
	    
	    int cax = 0;
	    for (auto p: freq){
	        cax = max(cax,p.second);
	    }
	    cout << n - cax << endl;
	}
}