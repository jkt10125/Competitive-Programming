#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];

    int q;
    cin >> q;
    while(q--) {
        int a;
        cin >> a;
        if(a == 1) {
            int x, y;
            cin >> x >> y;
            A[x] = y;
        }
        else {
            int l, r, g;
            cin >> l >> r >> g;
            int ans = 0;
            for(int i=l; i<=r; i++) {
                if(__gcd(g, A[i]) == 1) ans++;
            }
            cout << ans << endl;
        }
    }
}