/*
** Date: 28/12/2022 | Time: 12:53:58
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ans = n / i;
                break;
            }
        }
        cout << ans << ' ' << n - ans << endl;
    }
}