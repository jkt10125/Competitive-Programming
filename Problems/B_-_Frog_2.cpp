#include <iostream>
using namespace std;

#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    ll dp[n];
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        ll aa = 1e17;
        for(int j=max(0, i-k); j<i; j++) {
            aa = min(aa, dp[j]+abs(A[i]-A[j]));
        }
        dp[i] = aa;
    }

    cout<<dp[n-1];
}