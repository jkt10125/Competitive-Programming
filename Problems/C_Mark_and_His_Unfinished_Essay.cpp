#include <bits/stdc++.h>
using namespace std;

vector<int> A, L, R, S;
int n, c, q;

int f(int k) {
    if(k <= n) return k;
    auto a = --upper_bound(S.begin(), S.end(), k);
    int val = a - S.begin();
    return f(k-*a+L[val]-1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> c >> q;
        string s;
        cin >> s;
        s = "0" + s;
        L.resize(c);
        R.resize(c);
        for(int i=0; i<c; i++) {
            cin >> L[i] >> R[i];
        }
        S.resize(c+1);
        S[0] = n;
        for(int i=1; i<=c; i++) {
            S[i] = S[i-1] + R[i-1] - L[i-1] + 1;
        }

        for(int i=0; i<q; i++) {
            int k;
            cin >> k;
            cout<<f(k)<<"\n";
        }
    }
}