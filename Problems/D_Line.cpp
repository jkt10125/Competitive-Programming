#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int p = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') p += i;
            else p += (n - i - 1);
        }
        vector<int> ans(n);
        int l=0, r = n-1;
        int ctr = 0;
        while(l < r) {
            if(s[l] == 'L') {
                p -= l;
                p += (n - l - 1);
                s[l] = 'R';
                ans[ctr++] = p;
            }
            if(s[r] == 'R') {
                p -= n - r - 1;
                p += r;
                s[r] = 'L';
                ans[ctr++] = p;
            }
            l++; r--;
        }
        while(ctr < n) ans[ctr++] = p;

        for(int i=0; i<n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}