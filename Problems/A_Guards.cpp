#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> A(n+1);
    for(ll i=1; i<=n; i++) cin >> A[i];

    vector<ll> psum(n+1, 0);
    for(ll i=1; i<=n; i++) psum[i] = psum[i-1] + A[i];

    vector<vector<ll>> dp(m+1, vector<ll> (n+1, 1e17));

    for(ll i=0; i<=m; i++) dp[i][0] = 0;
    for(ll i=1; i<=n; i++) dp[0][i] = -1;
    for(ll i=1; i<=n; i++) {
        dp[1][i] = i * psum[i];
    }

    for(ll i=2; i<=m; i++) {
        for(ll j=1; j<=n; j++) {
            // dp[i][j] = min(dp[i][j], dp[i-1][k] + (j-k)*(psum[j]-psum[k]))
            if(i > j) dp[i][j] = dp[i-1][j];
            for(ll k=1; k<j; k++) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + (j-k)*(psum[j]-psum[k]));
            }
        }
    }

    for(ll i=0; i<=m; i++) {
        for(ll j=0; j<=n; j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    cout<<dp[m][n];
}