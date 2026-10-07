#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n,m;
    string s,l;
    cin>>n>>m>>s>>l;
    bool leftkey[26]={};
    for(char c:l){
        leftkey[c -'a']=true;
    }
    int longest=0,current=0;
    char pre ='\0';
    for(char c:s){
      char hand =leftkey[c-'a']? 'l':'r';
      if(hand== pre){
          ++current;
      }
      else{
          current=1;
          pre =hand;
      }
      longest = max(longest,current);
    }
    cout<<longest<<endl;
}
   
}