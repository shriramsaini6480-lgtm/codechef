#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
      int n;
      string s;
      cin>>n>>s;
      int op=0;
      int str=0;
      char pre='\0';
      for(char b:s){
          if(b==pre){
              ++str;
          }
          else{
              pre=b;
              str=1;
          }
          if(str==3){
              ++op;
              str=0;
              pre='\0';
          }
      }
      cout<<op<<endl;
  }
   
}