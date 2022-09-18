#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, b, s;
        cin >> n >> k >> b >> s;
        if(s > (n * (k-1) + b * k)) cout<<-1<<endl;
        else if(s < b * k) cout<<-1<<endl;
        else {
            int ans[n] = {0};
            int a = b / n;
            int c = b % n;
            for(int i=0; i<n; i++) ans[i] = a * k;
            for(int i=0; i<c; i++) ans[i] += k;
            s -= b * k;
            int ctr = 0;
            while(s > k-1) {
                ans[ctr++] += k-1;
                s -= k-1;
            }
            ans[ctr] += s;

            for(int i=0; i<n; i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
}