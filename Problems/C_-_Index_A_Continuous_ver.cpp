#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    int ctr = 0;
    for(int i=0; i<m; i++) ctr += (i+1) * A[i];
    int ans = ctr;

    vector<int> psum(n, A[0]);
    for(int i=1; i<n; i++) psum[i] = psum[i-1] + A[i];
    for(int i=m; i<n; i++) {
        ctr += m * A[i];
        ctr -= psum[i-1];
        if(i > m) ctr += psum[i-m-1];
        ans = max(ans, ctr);
    }

    cout<<ans;
}