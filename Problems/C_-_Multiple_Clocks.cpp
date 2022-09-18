#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    cin >> n;
    ll ans;
    cin >> ans; n--;
    while(n--) {
        ll x; cin >> x;
        ans = ans / __gcd(x, ans) * x;
    }

    cout << ans;
}