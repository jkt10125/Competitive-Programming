#include <bits/stdc++.h>
#include <my_template>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<vector<ll>> A(n+1);
        for(ll i=1; i<=n; i++) A[i].push_back(-1);

        for(ll i=0; i<n; i++) {
            ll x;
            cin >> x;
            A[x].push_back(i);
        }

        for(ll i=1; i<=n; i++) A[i].push_back(n);

        ll ans = 0;
        for(ll i=1; i<=n; i++) {
            for(ll j=1; j<A[i].size(); j++) {
                ll l = max(A[i][j-1]+1, A[i][j]-i+1);
                ll r = min(A[i][j], n-i);
                if(r>=l) ans += (r-l+1);
            }
        }
        cout<< ans<<"\n";
    }
}