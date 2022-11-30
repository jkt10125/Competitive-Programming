#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second > b.first * a.second;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> A(n);
        for(int i=0; i<n; i++) cin >> A[i].first;
        for(int i=0; i<n; i++) cin >> A[i].second;

        sort(A.begin(), A.end(), cmp);

        int ans = 0;
        int l = 0;
        for(int i=1; i<n; i++) {
            l += A[i-1].first;
            ans += l * A[i].second;
        }
        
        cout << ans << endl;
    }
}