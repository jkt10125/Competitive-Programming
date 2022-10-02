#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> A;
int t;
bool f(int m) {
    int p = 0;
    for(int i : A) {
        p += (m / i
        );
    }
    return (p >= t);
}

signed main() {
    int n;
    cin >> n >> t;
    A.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];

    int l = 0, r = 1e18;
    int ans;
    while(l <= r) {
        int m = (l + r) / 2;
        if(f(m)) {
            ans = m;
            r = m-1;
        }
        else {
            l = m+1;
        }
    }

    cout<<ans;
}