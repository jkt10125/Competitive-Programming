#include <bits/stdc++.h>
using namespace std;

#define int long long

int back(set<int> &s) {
    return *(--s.end());
}

signed main() {
    int t = 1;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n+1);
        for(int i=0; i<n; i++) cin >> A[i+1];

        set<int> cwi;
        cwi.insert(0);
        int ans = 0;
        for(int i=1; i<=n; i++) {
            int ele = 0;
            if(A[i] - i < A[back(cwi)] - back(cwi)) {
                cwi.insert(i);
                ans += A[i];
            }
            else {
                ans += min(i - back(cwi) + A[back(cwi)], i);
            }
        }
cerr<<ans;
        int q;
        cin >> q;
        while(q--) {
            int p, x;
            int a1 = ans;
            cin >> p >> x;
            int idx = *(--cwi.upper_bound(p));
            if(A[p] - p < A[idx] - idx) {
                ans -= A[p];
            }
            else {
                ans -= min(p - idx + A[idx], p);
            }

            if(x - p < A[idx] - idx) {
                ans += x;
            }
            else {
                ans += min(p - idx + A[idx], p);
            }

            cout << ans << endl;

            ans = a1;
        }
    }
}