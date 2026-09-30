#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m,k;
	    cin >> n >> m >> k;
	    
	    vector<int> occupied(n + 1 ,0);
	    for (int i=0;i<m;i++){
	        int x;
	        cin >> x;
	        occupied[x] = 1;
	    }
	    for (int per = 0;per<k;per++){
	        for (int seat=1;seat<=n;seat++){
	            if (occupied[seat] == 0){
	                cout << seat << " ";
	                occupied[seat] = 1;
	                break;
	            }
	        }
	    }
	    cout << endl;
	}

}