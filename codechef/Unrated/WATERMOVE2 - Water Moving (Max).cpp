#include <bits/stdc++.h>
using namespace std;

int main(){
 int t;
 cin>>t;
 while(t--){
     int n,k;
     cin>>n>>k;
     vector<long long>a(n);
     for(auto&x:a)
     cin>>x;
     sort(a.rbegin(), a.rend());
      long long answer = 0;
       int count=min(n,k+1);
       for(int i=0;i<count;++i){
           answer+=a[i];
       }
       cout<<answer<<endl;
 }
   
}