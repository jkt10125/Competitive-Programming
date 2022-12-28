/*
** Date: 28/12/2022 | Time: 09:58:54
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
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        int cnt[2*n + 7] = {1};
        int pref = 0;
        int ans = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            pref ^= A[i];
            for (int j = 0; j * j < 2*n + 7; j++) {
                int nreq = (pref ^ (j*j));
                if (nreq < 2*n + 7) {
                    ans -= cnt[nreq];
                }
            }
            cnt[pref]++;
        }

        cout << ans << endl;
    }
}