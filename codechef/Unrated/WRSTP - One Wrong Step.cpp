#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n;
     string s;
     cin>>n>>s;
     int x=0,y=0;
     for(char m:s){
          if (m=='U') 
          ++y;
        else if (m=='D') 
          --y;
        else if (m=='R') 
          ++x;
        else if (m=='L') 
          --x;
      }
      if((abs(x)==2 && y==0)||(abs(y)==2 && x==0)){
          cout<<"yes"<<endl;
      }
      else{
          cout<<"no"<<endl;
      }
}
   
}