/*
** Date: 28/12/2022 | Time: 13:11:44
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            sum += x;
            if (i + j == n - 1) {
                mn = min(mn, x);
            }
        }
    }

    cout << sum - mn << endl;
}