#include <iostream>
using namespace std;

#define ll long long

int main() {
    int n, k;
    cin >> n >> k;

    int w[n+1], v[n+1];
    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];

    int sum = 0;
    for(int i=1; i<=n; i++) sum += v[i];

    ll dp[2][sum+1];
    for(int i=1; i<=sum; i++) dp[0][i] = 1e9 + 7;
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(j >= v[i]) {
                dp[1][j] = min(dp[0][j], dp[0][j-v[i]] + w[i]);
            }
            else dp[1][j] = dp[0][j];
        }
        for(int j=0; j<=sum; j++) dp[0][j] = dp[1][j];
    }
    for(int i=sum; i>=0; i--) {
        if(dp[0][i] <= k) { cout<<i; break; }
    }
}