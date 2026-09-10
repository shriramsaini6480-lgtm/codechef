#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
      int x1,y1,x2,y2;
      cin>>x1>>y1>>x2>>y2;
      if((x1+y1)<(x2+y2)){
          cout<<(x1+y1)<<endl;
      }
      else if((x1+y1)>(x2+y2)){
          cout<<(x2+y2)<<endl;
      }
      else{
        cout<<(x1+y1)<<endl;  
      }
  }
   
}