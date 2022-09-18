#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ctr = 0;
        int ps = 0, pt = 0;
        while(ps < n && pt < n) {
            if(ctr < 0) break;
            if(t[pt] == 'b') { ctr++, pt++; continue; }
            if(s[ps] == 'b') { ctr--, ps++; continue; }
            if(s[ps] == t[pt]) {
                ps++;
                pt++;
            }
            else break;
        }
        while(ps < n && s[ps] == 'b') ps++;
        if(pt != n || ps != n) cout<<"NO\n";
        else cout<<"YES\n";
    }
}