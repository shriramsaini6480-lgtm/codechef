#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      if((a-c)>(b-d)){
          cout<<"second"<<endl;
          
      }
      else if((a-c)<(b-d)){
          cout<<"first"<<endl;
      
      }
      else{
          cout<<"any"<<endl;
      }
  }
   
}