#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];
    long long psum[n+1] = {0};
    for(int i=1; i<=n; i++) psum[i] = psum[i-1] + A[i];
 
    long long dp[n+1][n+1];
    // dp[i][j] : what will be the ans if we consider the subarray from i to j
 
    for(int i=1; i<=n; i++) dp[i][i] = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<i; j++) {
            dp[i][j] = -2e9;
        }
    }
    dp[0][0] = 0;
 
    for(int j=1; j<=n; j++) {
        for(int i=j-1; i>0; i--) {
            dp[i][j] = max(psum[j]-psum[i] - dp[i+1][j], psum[j-1]-psum[i-1] - dp[i][j-1]);
        }
    }
 
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=n; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
 
    cout<<dp[1][n];
}