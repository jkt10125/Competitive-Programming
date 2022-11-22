#include <bits/stdc++.h>
using namespace std;

#define int long long

int f (int a, int b) {
    int t = (b + 1) / a;
    return (a * t * (t - 1) / 2 + (b + 1 - a * t) * t) % 1000000007;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a = (a) ? --a : a;
        int ans = 0;
        for (int i = 5; i < 1e9; i *= 5) {
            ans += f(i, b) - f(i, a);
            ans %= (1000000007);
        }
        cout << (ans + 1000000007) % 1000000007 << endl;
    }
}