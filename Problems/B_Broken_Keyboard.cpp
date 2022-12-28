/*
** Date: 28/12/2022 | Time: 13:32:53
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

        bool ok = true;
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            if (ctr & 1) {
                if (i == n - 1 || s[i] != s[i + 1]) {
                    ok = false;
                }
                i++;
            }
            ctr++;
        }

        const string out[] = {"NO", "YES"};
        cout << out[ok] << endl;
    }
}