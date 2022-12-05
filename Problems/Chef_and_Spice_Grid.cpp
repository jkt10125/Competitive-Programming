#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if(n * m < k) cout << "NO\n";
        else if(k % n == 0 || k % m == 0) cout << "YES\n";
        else {
            bool ok = false;
            for(int x = 0; m * x < k && x < n; x++) {
                if ((k - m * x) % (n - x) == 0) {
                    ok = true;
                    break;
                }
            }

            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}