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
        string a;
        a += s[0];
        for(int i=1; i<n; i++) {
            if(s[i] != s[i-1]) a += s[i];
        }
        if(a.size() == 1) {
            if(a[0] != 'W') cout<<"NO\n";
            else cout<<"YES\n";
        }
        else if(a.size() == 2) {
            if(a[0] == 'W' || a[1] == 'W') cout<<"NO\n";
            else cout<<"YES\n";
        }
        else {
            n = a.size();
            int aa = 1;
            for(int i=1; i<n-1; i++) {
                if(a[i] == 'R') {
                    if(a[i-1] != 'B' && a[i+1] != 'B') aa = 0;
                }
                else if(a[i] == 'B') {
                    if(a[i-1] != 'R' && a[i+1] != 'R') aa = 0;                    
                }
            }
            if(a[0] == 'R' && a[1] != 'B') aa = 0;
            if(a[0] == 'B' && a[1] != 'R') aa = 0;
            if(a[n-1] == 'R' && a[n-2] != 'B') aa = 0;
            if(a[n-1] == 'B' && a[n-2] != 'R') aa = 0;
            if(aa) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    
}