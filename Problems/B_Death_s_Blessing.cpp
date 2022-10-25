#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        int mx = INT_MIN;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            sum += x;
            mx = max(mx, x);
        }

        cout << sum - mx << endl;

    }
}