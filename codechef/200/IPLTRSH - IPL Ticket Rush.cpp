#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n>> m;
        if(m>n){
            cout<<"0"<<endl;
        }
        else if(m==n){
            cout<<"0"<<endl;
        }
        else{
            cout<<n-m<<endl;
        }
    }

    return 0;
}