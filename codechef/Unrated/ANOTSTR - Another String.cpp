#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n;
    string a,b;
    cin>>n>>a>>b;
    int oa=count(a.begin(), a.end(), '1');
    int ob=count(b.begin(), b.end(), '1');
    cout<<(oa%2==ob%2 ? "yes\n":"no\n");
}
   
}