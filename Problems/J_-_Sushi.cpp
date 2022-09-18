#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[4] = {0};
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    double dp[n+1][n+1][n+1];
    // dp[i][j][k] : expected number of moves to finish i 1plated, j 2plated, k 3plated sushi.
    
    dp[0][0][0] = 0;

    for(int k=0; k<=n; k++) {
        for(int j=0; j<=n; j++) {
            for(int i=0; i<=n; i++) {
                if(i == j && j == k && k == 0) continue;
                if(i+j+k > n) continue;
                dp[i][j][k] = (i * dp[max(0, i-1)][j][k] + j * dp[i+1][max(0, j-1)][k] + k * dp[i][j+1][max(0, k-1)] + n) / (i + j + k);
            }
        }
    }

    cout<<setprecision(17)<<dp[cnt[1]][cnt[2]][cnt[3]];

}