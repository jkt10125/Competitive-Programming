#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool f = true;
        while(n) {
            if(n & 1) n--;
            if(s.substr(0, n/2) != s.substr(n/2, n/2)) {
                f = false;
                break;
            }
            n >>= 1;
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}