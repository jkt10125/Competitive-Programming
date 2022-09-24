#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout<<"Division ";
        if(n < 1400) cout<<4;
        else if(n < 1600) cout<<3;
        else if(n < 1900) cout<<2;
        else cout<<1;
        cout<<endl;
    }
}