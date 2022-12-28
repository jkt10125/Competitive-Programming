/*
** Date: 28/12/2022 | Time: 10:14:57
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }   

        auto f = [&n, &m, &A] (int len) {
            vector<vector<bool>> tmp(n, vector<bool> (m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    tmp[i][j] = (A[i][j] >= len);
                }
            }

            vector<vector<int>> dp(n, vector<int> (m));
            for (int i = 0; i < n; i++) dp[i][0] = tmp[i][0];
            for (int j = 0; j < m; j++) dp[0][j] = tmp[0][j];

            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (tmp[i][j]) {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                }
            }

            // cerr << "# " << len << endl;
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++) {
            //         cerr << tmp[i][j] << ' ';
            //     }
            //     cerr << endl;
            // }
            // cerr << endl;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dp[i][j] >= len) return true;
                }
            }
            return false;
        };

        int l = 1, r = n;
        int ans = 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (f(m)) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        cout << ans << endl;
    }
}