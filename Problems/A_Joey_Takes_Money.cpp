/*
** Date: 27/12/2022 | Time: 20:06:47
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
        int prod = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            prod *= x;
        }
        prod += n - 1;
        cout << 2022 * prod << endl;
    }
}