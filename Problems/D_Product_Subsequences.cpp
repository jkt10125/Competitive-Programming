#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1000000007;

int power (int a, int b) {
    if (b < 0) return 0;
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main () {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        int p = 0, n = 0, z = 0;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (!x) z++;
            else if (x > 0) p++;
            else n++;
        }

        // zero : (2^z - 1) * (2^(p + n))
        // pos  : (2^p) * (2^(n - 1)) - 1
        // neg  : pos + 1

        z = (power(2, z) + mod - 1) % mod * power(2, p + n) % mod;
        p = (n) ? (power(2, p) % mod * power(2, n - 1) - 1) % mod : (power(2, p) + mod - 1) % mod;
        n = (n) ? p + 1 : 0;

        cout << p << ' ' << n << ' ' << z << endl;
    }
}