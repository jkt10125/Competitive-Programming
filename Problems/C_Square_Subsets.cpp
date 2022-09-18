#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
map<ll, int> A;

int reduce(int a) {
    for(int p : prime) {
        int ctr = 0;
        while(a % p == 0) { ctr++; a /= p; }
        if(ctr & 1) a *= p;
    }
    return a;
}

ll power(ll a, ll b) {
    if(b == -1) return 1;
    ll res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

bool check(ll a) {
    ll b = sqrt(a);
    return b * b == a;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        A[reduce(a)]++;
    }

    ll ans = power(2, A[1]);
    for(int i=2; i<70; i++) ans *= power(2, A[i]-1);
    
    for(int i=1; i<(1 << 19); i++) {
        ll res = 1;
        ll mans = 1;
        for(int j=0; j<19; j++) {
            if(i & (1 << j)) {
                res *= prime[j];
                mans *= A[prime[j]];
            }
        }
        if(mans && A[res]) ans *= (mans * A[res]);
    }   
    cout<<ans-1;
}