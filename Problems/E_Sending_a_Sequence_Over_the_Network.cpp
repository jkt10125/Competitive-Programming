#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n+1] = {0}, dp[n+1] = {1};
        for(int i=1; i<=n; i++) cin >> A[i];

        for(int i=1; i<=n; i++) {
            if(dp[i-1] && i+A[i] <= n) dp[i + A[i]] = 1;
            if(i-A[i] >= 1 && dp[i-A[i]-1]) dp[i] = 1;
        }

        if(dp[n]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}