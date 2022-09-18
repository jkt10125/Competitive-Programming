#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int A[n][2];
    for(int i=0; i<n; i++) cin >> A[i][0];
    for(int i=0; i<n; i++) cin >> A[i][1];

    long long dp[n][2];
    dp[0][0] = A[0][0];
    dp[0][1] = A[0][1];
    dp[1][0] = A[0][1] + A[1][0];
    dp[1][1] = A[0][0] + A[1][1];
    
    for(int i=2; i<n; i++) {
        dp[i][0] = max(max(dp[i-2][0], dp[i-2][1]), dp[i-1][1]) + A[i][0];
        dp[i][1] = max(max(dp[i-2][0], dp[i-2][1]), dp[i-1][0]) + A[i][1];
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}