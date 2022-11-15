#include <bits/stdc++.h>
using namespace std;

#define i64 long long

int main() {
    int t;
    cin >> t;
    while(t--) {
        i64 a, b;
        cin >> a >> b;
        i64 a_ = a;
        bool ok = true;
        i64 hcf = __gcd(a, b);
        while(hcf != 1) {
            b = b / hcf;
            hcf = __gcd(a, b);
        }
        if(a_ % b) ok = false;

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}