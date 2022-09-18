#include <bits/stdc++.h>
using namespace std;

template <typename T> 
T input() { T a; cin >> a; return a; }

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s = input<string>();
        long long ans = 0;
        int n = s.size();
        int len = 1;
        for(int i=1; i<n; i++) {
            if(s[i] == '?') len++;
            else if(s[i] != s[i-1]) len++;
            else {
                ans += len * 1ll * (len + 1) / 2;
                len = 1;
            }
        }
        ans += len * 1ll * (len + 1) / 2;
        cout<<ans<<"\n";
    }
}