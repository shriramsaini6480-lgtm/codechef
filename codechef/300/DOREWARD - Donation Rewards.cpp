#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
      int x;
      cin>>x;
      if(x<=3){
          cout<<"bronze"<<endl;
      }
      else if(x>3&&x<=6){
          cout<<"silver"<<endl;
      }
      else{
          cout<<"gold"<<endl;
      }
  }
   
}