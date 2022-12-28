/*
** Date: 27/12/2022 | Time: 17:10:49
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100001;
const int mod = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A[N] = {0};
    A[0] = A[1] = 1;
    for (int i = 2; i < N; i++) {
        A[i] = (A[i - 1] + A[i - 2]) % mod;
    }
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            ok = false;
            break;
        }
        if (s[i] == 'u' || s[i] == 'n') {
            char c = s[i];
            int ctr = 0;
            while (s[i] == c && i < n) {
                ctr++;
                i++;
            }
            i--;
            ans = (ans * A[ctr]) % mod;
        }
    }
    if (ok) cout << ans << endl;
    else cout << 0 << endl;
}