#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    vector<vector<int>> dp(n + 1, vector<int> (n + 1));

    for (int j = 1; j <= n; j++) {
        for (int i = n; i >= 1; i--) {
            if(i > j) continue;
            if(i == j) dp[i][j] = A[i];
            else {
                dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]);
            }
        }
    }

    cout << ((sum + dp[1][n]) >> 1);
}