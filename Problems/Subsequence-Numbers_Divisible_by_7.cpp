#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1000000007;

ll f(int n) { 
    ll ans = 1;
    for(int i=0; i<=log10(n); i++) ans *= 10;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n+1);
        for(int i=1; i<=n; i++) cin >> A[i];

        vector<vector<ll>> dp(n+1, vector<ll>(7, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<7; j++) {
                dp[i][(j*f(A[i]) + A[i]) % 7] += dp[i-1][j];
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
        // cerr << dp;
        cout<<(dp[n][0] - 1 + mod) % mod<<"\n";
    }
}