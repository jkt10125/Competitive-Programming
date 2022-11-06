#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int p = a * b;
        int p1 = -1, p2 = -1;
        bool ok = false;
        for(int i=a+1; i<=c; i++) {
            if(ok) break;
            int k = i / __gcd(p, i);
            k = p * k / i;
            for(int j=k; j<=d; j+=k) {
                if(j>b) {
                    p1 = i;
                    p2 = j;
                    ok = true;
                    break;
                }
            }
        }

        cout << p1 << " " << p2 << endl;
    }
}