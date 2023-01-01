/*
** Date: 31/12/2022 | Time: 12:34:05
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        int ans = 0;

        if (n > 3) {
            ans = n * 1ll * (*max_element(A.begin(), A.end()));
        }
        else if (n == 2) {
            ans = max(A[0]+A[1], 2 * abs(A[0]-A[1]));
        }
        else {
            ans = A[0] + A[1] + A[2];
            // first case
            int v = abs(A[1] - A[0]);
            ans = max(ans, 2ll * v + A[2]);
            ans = max(ans, 3ll * v);
            // second case
            v = abs(A[1] - A[2]);
            ans = max(ans, 2ll * v + A[0]);
            ans = max(ans, 3ll * v);
            ans = max(ans, 3ll * max(A[0], A[2]));
        }

        cout << ans << endl;
    }
}