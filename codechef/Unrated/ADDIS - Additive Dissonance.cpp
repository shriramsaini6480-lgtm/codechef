#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while (t--){
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
        
    }
    int ans=0;
    for(auto p:mp){
        int f=p.second;
        int value =(f+1)/2;
        ans=max(ans,value);
    }
    cout<<ans<<endl;
}
   
}