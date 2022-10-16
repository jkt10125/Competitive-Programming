#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        int o = 0, e = 0, sum = 0;
        while(n--) {
            int x;
            cin >> x;
            sum += x;
            if(x & 1) o++;
            else e++;
        }

        while(q--) {
            int a, x;
            cin >> a >> x;
            if(a) {
                sum += o * x;
                if(x & 1) {
                    e += o;
                    o = 0;
                }
            }
            else {
                sum += e * x;
                if(x & 1) {
                    o += e;
                    e = 0;
                }
            }

            cout << sum << endl;
        }
    }
}