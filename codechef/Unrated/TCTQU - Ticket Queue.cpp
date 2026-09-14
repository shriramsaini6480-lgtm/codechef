#include <bits/stdc++.h>
using namespace std;

int main(){
int n,k;
cin>>n>>k;
vector<long long> t(n);
for(int i=0;i<n;i++){
    cin>>t[i];
    
}
long long ans=0;
long long time=t[k];
for(int i=0;i<n;i++){
    if(i<=k){
        ans+=min(t[i],time);
        }
        else{
            ans+=min(t[i],time-1);
        }
}
cout<<ans;
   
}