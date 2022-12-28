/*
** Date: 28/12/2022 | Time: 12:18:27
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> dp(n + 1);
        for (int i = n; i > 0; i--) {
            int a = n / i;
            dp[i] = a * (a - 1) / 2;
            for (int j = i + i; j <= n; j += i) {
                dp[i] -= dp[j];
            }
        }

        int cost = 0;
        int idx = n;
        while (m && idx > 1) {
            int edge_count = dp[idx] / (idx - 1) * (idx - 1);
            if (m < edge_count) {
                edge_count = m / (idx - 1) * (idx - 1);
            }
            m -= edge_count;
            cost += edge_count / (idx - 1) * idx;
            idx--;
        }
        if (m) cout << -1 << endl;
        else cout << cost << endl;
    }
}