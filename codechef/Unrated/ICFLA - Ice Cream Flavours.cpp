#include <bits/stdc++.h>
using namespace std;

int main(){
 long long n;
 cin>>n;
 long long low=1,high =20000000000ll;
 long long flavours =0;
 while(low<=high){
     long long mid=(low +high)/2 ;
     long long types=mid*(mid-1)/ 2;
     if(types<=n){
         flavours=mid;
         low =mid+1;
         }
         else{
             high =mid -1;
         }
 }
 long long m=flavours*(flavours-1)/2;
 long long extra =n-m;
 cout<<flavours + extra;
   
}