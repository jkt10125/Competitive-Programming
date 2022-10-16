#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    for(int _i=1; _i<=t; _i++) {
        cout << "Case #" << _i << ": ";
        int n, m, p;
        cin >> n >> m >> p;
        int A[n][m];
        p--;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> A[i][j];
            }
        }

        int ans = 0;
        for(int j=0; j<m; j++) {
            int mx = 0;
            for(int i=0; i<n; i++) {
                mx = max(mx, A[i][j]);
            }
            ans += mx - A[p][j];
        }
        cout<<ans<<endl;
    }
}