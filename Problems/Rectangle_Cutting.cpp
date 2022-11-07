#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(501, vector<int> (501, 1000000));

    for (int i = 1; i <= 500; i++) {
        dp[i][1] = dp[1][i] = i - 1;
    }

    for (int i = 2; i <= 500; i++) {
        dp[i][i] = 0;
        for (int j = i + 1; j <= 500; j++) {
            for (int k = 1; k < j; k++) {
                dp[i][j] = dp[j][i] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
            for(int k = 1; k < i; k++) {
                dp[i][j] = dp[j][i] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            } 
        }
    }

    cout << dp[n][m];
}