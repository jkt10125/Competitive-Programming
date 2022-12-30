/*
** Date: 28/12/2022 | Time: 20:27:59
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string t = s;
        reverse(t.begin(), t.end());
    
        int dp[n][n];
        dp[0][0] = (s[0] == t[0]);
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] | (s[i] == t[0]));
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = (dp[0][j - 1] | (s[0] == t[j]));
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                else {
                    dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }

        cout << dp[n - 1][n - 1] / 2 << endl;
    }
}