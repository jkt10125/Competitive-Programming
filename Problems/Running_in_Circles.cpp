#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        cout << "Case #" << _i << ": ";

        int l, n;
        cin >> l >> n;
        int ctr = 0;
        int dist = 0;
        char dir = '?';
        for (int i = 0; i < n; i++) {
            int a;
            char c;
            cin >> a >> c;
            if (dir == '?') {
                dir = c;
                dist = a % l;
                ctr += a / l;
            }
            else {
                if (dir == c) {
                    ctr += (dist + a) / l;
                    dist = (dist + a) % l;
                }
                else {
                    dir = c;
                    if (a >= dist) ctr += (a - dist) / l;
                    dist = (a - dist) % l;
                    // if(dist < 0) dist = -dist;
                }
            }
        }

        cout << ctr << endl;
    }
}