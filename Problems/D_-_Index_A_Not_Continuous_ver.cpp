#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> A(n+1);
    for(int i=1; i<=n; i++) cin >> A[i];

    vector<int> dp_curr(n+1), dp_prev(n+1, 0);

    for(int j=1; j<=m; j++) {
        int mx = -1e16;
        for(int i=0; i<j; i++) dp_curr[i] = -1e16;
        for(int i=j; i<=n; i++) {
            mx = max(mx, dp_prev[i-1]);
            dp_curr[i] = mx + j * A[i];
        }
        dp_prev = dp_curr;
    }

    

    cout<<*max_element(dp_prev.begin(), dp_prev.end());
}