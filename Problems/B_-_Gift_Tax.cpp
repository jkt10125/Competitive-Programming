#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> A;
ll n, a, b;
bool f(ll k) {
    int del_ctr = 0;
    int add_ctr = 0;
    for(int i : A) {
        if(i < k) add_ctr += (k-i+a-1) / a;
        else del_ctr += (i-k) / b;
    }
    return add_ctr <= del_ctr;
}

int main() {
    cin >> n >> a >> b;
    A.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];
    ll mx = -1;
    for(auto it : A) mx = max(mx, it);
    ll l = 1, r = mx;
    int ans = 0;
    while(l <= r) {
        ll m = (l + r) / 2;
        if(f(m)) {
            ans = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }

    cout<<ans;
}