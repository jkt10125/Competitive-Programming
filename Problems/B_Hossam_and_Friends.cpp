#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n+1, n+1);
        while(m--) {
            int a, b;
            cin >> a >> b;
            if(a > b) swap(a, b);
            A[a] = min(A[a], b);
        }

        int ans = 0;
        int ctr = n + 1;
        for(int i=n; i>=1; i--) {
            ctr = min(ctr, A[i]);
            ans += ctr - i;
        }

        cout << ans << endl;
    }
}