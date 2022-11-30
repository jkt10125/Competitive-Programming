#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        int ctr = n - 1;
        if(k >= n / 2) ans = n * (n - 1) / 2;
        else {
            ctr = 2*ctr - 1;
            int a = ctr % 4;
            ctr = ctr / 4;

            ans = 2 * ((ctr + 1) * ctr - (ctr - k) * (ctr - k + 1)) + a * k;
        }

        cout << ans << endl;
    }
}