#include <iostream>
using namespace std;

#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    int w[n+1], v[n+1];
    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];

    ll dp[2][k+1];
    for(int i=0; i<=k; i++) dp[0][i] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            if(j >= w[i]) {
                dp[1][j] = max(dp[0][j], dp[0][j-w[i]] + v[i]);
            }
            else dp[1][j] = dp[0][j];
        }
        for(int j=0; j<=k; j++) dp[0][j] = dp[1][j];
    }

    cout<<dp[0][k];
}