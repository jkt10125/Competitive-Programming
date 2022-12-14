#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = (1 - (s[0] == t[0]));
    for (int j = 1; j < m; j++) {
        if (dp[0][j - 1] == j - 1) {
            dp[0][j] = j;
        }
        else {
            dp[0][j] = j + (1 - (s[0] == t[j]));
        }
    }

    for (int i = 1; i < n; i++) {
        if (dp[i - 1][0] == i - 1) {
            dp[i][0] = i;
        }
        else {
            dp[i][0] = i + (1 - (s[i] == t[0]));
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
    }
    cout << dp[n - 1][m - 1];
}