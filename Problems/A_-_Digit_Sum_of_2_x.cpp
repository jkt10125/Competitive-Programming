#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 2*n;
    cout<<m<<endl;
    if(n % 2 == 0) {
        if(n % 4 == 0) {
            n /= 4;
            while(n--) cout<<"4";
        }
        else {
            n /= 4;
            cout<<"2";
            while(n--) cout<<"4";
        }
    }
    else {
        if(n % 4 == 1) {
            cout<<"1";
            n /= 4;
            while(n--) cout<<"4";
        }
        else {
            cout<<n%4;
            n /= 4;
            while(n--) cout<<"4";
        }
    }
}