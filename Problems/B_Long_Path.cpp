#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<long long> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<long long> dp(n+2);
    // dp[i+1] = 2*dp[i] + 2 - dp[A[i]];
    for(int i=1; i<=n; i++) {
        dp[i+1] = 2*dp[i] + 2 - dp[A[i]];
        dp[i+1] %= mod;
    }

    cout << (dp[n+1] + mod) % mod << endl;
}