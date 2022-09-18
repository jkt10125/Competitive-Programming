#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];

    long long dp_prev[n+1], dp_curr[n+1];
    // dp[i][j] : what will be the ans if we consider the subarray from i to j
    // dp[i][j] = max(A[i] - dp[i+1][j], A[j] - dp[i][j-1]);

    dp_prev[0] = 0;
    for(int i=1; i<=n; i++) dp_prev[i] = -2e9;

    for(int j=1; j<=n; j++) {
        for(int i=j+1; i<=n; i++) dp_curr[i] = -2e9;
        dp_curr[j] = A[j];
        for(int i=j-1; i>0; i--) {
            dp_curr[i] = max(A[i]-dp_curr[i+1], A[j]-dp_prev[i]);
        }
        for(int i=0; i<=n; i++) dp_prev[i] = dp_curr[i];
    }

    cout<<dp_prev[1];
}