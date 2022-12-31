/*
** Date: 30/12/2022 | Time: 19:26:35
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
        for (int i = 1; i < n; i++) {
            if (A[i - 1] == 0) continue;
            ans++;
            A[i] = (A[i] == A[i - 1]) ? 0 : (A[i] ^ A[i - 1]);
        }

        cout << ans << endl;
    }
}