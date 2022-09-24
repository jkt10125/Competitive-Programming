#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        vector<int> p(n, a[0]), s(n, a[n-1]);
        for(int i=1; i<n; i++) p[i] = p[i-1] + a[i];
        for(int i=n-2; i>=0; i--) s[i] = s[i+1] + a[i];
        reverse(s.begin(), s.end()); 

        int ans = 0;
        for(int i=0; i<n; i++) {
            auto it = lower_bound(s.begin(), s.end(), p[i]);
            if(*it != p[i]) continue;
            if(it - s.begin() + i + 2 > n) continue;
            ans = it - s.begin() + i + 2;
        }
        cout<<ans<<endl;
    }
}