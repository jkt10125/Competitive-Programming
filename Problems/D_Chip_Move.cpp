#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int> (640, 0));
    
    for(int i=k; i<=n; i++) {
        dp[i][1] = (i % k) ? 0 : 1;
    }
 
    for(int i=k; i<=n; i++) {
        for(int j=2; j<640; j++) {
            for(int c=1; i-c*(k+j-1) > 0; c++) {
                dp[i][j] = (dp[i][j] + dp[i-c*(k+j-1)][j-1]) % mod;
            }
            if(i < k+j-1) break;
        }
    }

    vector<int> ans(n+1);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<640; j++) {
            ans[i] = (ans[i] + dp[i][j]) % mod;
        }
    } 
 
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";    
}