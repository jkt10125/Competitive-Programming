#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int A[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int dp[n][m];
    for (int i = 0; i < m; i++) {
        dp[0][i] = A[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m - 1; j++) {
            dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + A[i][j];
        }
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][0];
        dp[i][m - 1] = min(dp[i - 1][m - 1], dp[i - 1][m - 2]) + A[i][m - 1];
    }

    int M = INT_MAX;
    for (int i = 0; i < m; i++) {
        M = min(M, dp[n - 1][i]);
    }

    cout << M;
}