#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    long double A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];
    long double dp[2][n+1];
    dp[0][0] = 1.0;

    for(int i=1; i<=n; i++) {
        dp[1][0] = dp[0][0] * (1 - A[i]);
        for(int j=1; j<=n; j++) {
            if(j < i) dp[1][j] = dp[0][j]*(1 - A[i]) + dp[0][j-1]*(A[i]);
            else if(j == i) dp[1][j] = dp[0][j-1]*(A[i]);
            else dp[1][j] = 0;
        }
        for(int j=0; j<=n; j++) dp[0][j] = dp[1][j];
    }

    long double sum = 0.0;
    for(int i=n/2+1; i<=n; i++) sum += dp[0][i];

    cout << setprecision(10) << sum;
}