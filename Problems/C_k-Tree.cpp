#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int n;
int f(int k) {
    int dp[n+1] = {1};
    int sum = 1;
    for(int i=1; i<=k; i++) {
        dp[i] = sum;
        sum = (sum + dp[i]) % mod;
    }
    sum = (sum + mod - 1) % mod;
    for(int i=k+1; i<=n; i++) {
        dp[i] = sum;
        sum = (sum + dp[i]) % mod;
        sum = (sum + mod - dp[i-k]) % mod;
    }
    return dp[n];
}

signed main() {
    int k, d;
    cin >> n >> k >> d;
    k = min(k, n);
    d = min(d, n+1);
    cout<<(f(k) - f(d-1) + mod) % mod;
}