/*
** Date: 30/12/2022 | Time: 20:06:57
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n), B(m);

        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];

        for (int i = 0; i < m; i++) {
            int idx = 0;
            for (int j = 0; j < n; j++) {
                if (A[j] < A[idx]) idx = j;
            }
            A[idx] = B[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += A[i];
        }
        cout << ans << endl;
    }
}