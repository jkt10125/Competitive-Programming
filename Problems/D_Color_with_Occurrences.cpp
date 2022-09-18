#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        string t;
        cin >> t;
        int m = t.size();
        t = "-" + t;
        int n;
        cin >> n;
        map<string, int> s;
        for(int i=0; i<n; i++) {
            string x;
            cin >> x;
            s[x] = i+1;
        }

        vector<int> dp(m+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=m; i++) {
            int j = 1;
            for(; j<=i; j++) {
                if(s[t.substr(j, i-j+1)] != 0) {
                    break;
                }
            }
            if(j > i) continue;
            int mn = INT_MAX;
            for(int k = j-1; k<i; k++) {
                mn = min(mn, dp[k]);
            }
            if(mn == INT_MAX) continue;
            dp[i] = mn+1;
        }
        if(dp[m] == INT_MAX) cout<<"-1\n";
        else {
            cout<<dp[m]<<"\n";
            int ctr=m;
            while(ctr != 0) {
                int j=1;
                for(; j<=ctr; j++) {
                    if(s[t.substr(j, ctr-j+1)] != 0) break; 
                }
                assert(j <= ctr);
                cout<<s[t.substr(j, ctr-j+1)]<<" "<<j<<"\n";
                for(int i=ctr-1; i>=0; i--) {
                    if(dp[i] == dp[ctr] - 1) {
                        ctr = i;
                        break;
                    }
                }
            }
        }
        for(int i=0; i<=m; i++) cerr<<dp[i]<<" ";
        cerr<<" "<<t<<"\n";
    }
}