#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n+1, 0);
        for(int i=1; i<=n; i++) cin >> A[i];

        int c = log2(n);
        c = (1 << (c + 1)) - 1;
        c = n * (n - 1) - k * c;
        c = max(c, 1ll);
        int ans = INT_MIN;
        for(int i=1; i<=n; i++) {
            for(int j=n; i*j >= c; j--) {
                if(i == j) continue;
                ans = max(ans, i * j - k * (A[i] | A[j]));
            }
        }
        cout<< ans << endl;
    }
}