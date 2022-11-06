#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<array<int, 2>> divisors(int n) {
    vector<int> p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        p.push_back(n);
    }
    
    n = p.size();
    vector<array<int, 2>> a(1 << n);
    a[0] = {1, 1};
    for (int i = 1; i < (1 << n); i++) {
        int j = __builtin_ctz(i);
        auto [x, y] = a[i ^ (1 << j)];
        a[i] = {x * p[j], -y};
    }
    return a;
}

int mod = 998224353ll;

int f(int a, int m) { // TC : sqrt(a)
    // for 1 <= x <= m
    // return #(gcd(a, x) = 1)
    int ans = 0;
    for(auto [x, y] : divisors(a)) {
        ans += y * (m / x);
    }
    return ans % mod;
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int A[n];
        for(int i=0; i<n; i++) cin >> A[i];

        int ans = 1;
        for(int i=1; i<n; i++) {
            if(A[i-1] % A[i]) {
                ans = 0;
                break;
            }
            int res = 0;
            for (auto [x, u] : divisors(A[i - 1] / A[i])) {
                res += u * (m / A[i] / x);
            }
            ans = ans * res % mod;
        }
        cout << ans << endl;
    }
}

