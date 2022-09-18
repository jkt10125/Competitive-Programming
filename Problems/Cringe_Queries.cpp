#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long

const ll mod = 998244353;

ll power(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a = a * a;
        a = a % mod;
        ans = ans % mod;
        b = b >> 1;
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    set<pii> A, B;
    while(q--) {
        pii X;
        cin >> X.ff >> X.ss;
        A.insert({X.ff, X.ss});
        B.insert({-X.ss, -X.ff});
    }
    
    for(auto it=A.begin(); it != (--A.end()); it++) {
        auto it1 = it;
        it1++;
        while(it1->ff == it->ff && it1 != A.end()) {
            int a = it->ss + 1;
            int b = it1->ss;
            A.erase(it1);
            B.erase(B.find({-it1->ss, -it1->ff}));
            A.insert({a, b});
            B.insert({-b, -a});
            it1 = it; it1++;
        }
    }
    
    for(auto it=B.begin(); it != (--B.end()); it++) {
        auto it1 = it;
        it1++;
        while(it1->ff == it->ff && it1 != B.end()) {
            int a = it->ss + 1;
            int b = it1->ss;
            B.erase(it1);
            B.insert({a, b});
            it1 = it; it1++;
        }
    }
    
    set<pii> C;
    for(auto it : A) C.insert({it.ff, it.ss});
    for(auto it : B) C.insert({-it.ss, -it.ff});
    
    ll b = C.size();
    // for(auto it : C) cerr<<it.ff<<" "<<it.ss<<endl;

    cout<<power(2ll, b) << endl;
}