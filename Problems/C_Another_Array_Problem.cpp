#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 4) {
            int ans, A[n];
            for (int i = 0; i < n; i++) {
                cin >> A[i];
            }
            if (n == 2) {
                ans = max(A[0] + A[1], abs(A[1] - A[0]) * 2);
            }
            else if (n == 3) {
                int v = *max_element(A, A + 3);
                if (A[0] == v || A[2] == v) {
                    ans = 3 * v;
                }
                else {
                    ans = max(A[0], A[2]) * 3;
                    ans = max(ans, accumulate(A, A + 3, 0ll));
                    ans = max(ans, (v - min(A[0], A[2])) * 3);
                }
            }
            cout << ans << endl;
        }
        else {
            int val = 0;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                val = max(val, x);
            }
            cout << val * n << endl;
        }
    }
}