#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int dp[n+1] = {0};
        int ans = 0;
        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            dp[i] = min(dp[i-1]+1, x);
            ans += dp[i];
        }
        cout << ans << endl;
    }
}