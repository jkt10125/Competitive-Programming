#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    const int N = 1e6;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = INT_MAX;
        for(int x = 0; x < N; x++) {
            int y = (b + a + x - 1) / (a + x) * (a + x) - b;
            ans = min(ans, x + y);
        }

        cout << ans << endl;
    }
}