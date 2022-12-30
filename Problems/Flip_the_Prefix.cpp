/*
** Date: 28/12/2022 | Time: 20:06:30
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (k == 1) {
            bool ok = false;
            for (char c : s) {
                if (c == '1') {
                    ok = true;
                }
            }
            if (ok) cout << 0;
            else cout << 1;
            cout << endl;
        }
        else {
            int ctr = 0;
            for (int i = 1; i < k; i++) {
                if (s[i] != s[i - 1]) {
                    ctr++;
                }
            }
            int ans = ctr;
            if (s[k - 1] == '0') ans++;

            for (int i = k; i < n; i++) {
                if (s[i - k] != s[i - k + 1]) {
                    ctr--;
                }
                if (s[i] != s[i - 1]) {
                    ctr++;
                }
                int c = ctr;
                if (s[i] == '0') c++;
                ans = min(ans, c);
            }

            cout << ans << endl;
        }
    }
}