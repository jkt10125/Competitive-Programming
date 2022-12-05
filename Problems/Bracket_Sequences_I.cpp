#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000004;
const int M = 1000000007;

int fact[N];
int ifac[N];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= M;
        }
        a *= a;
        b >>= 1;
        a %= M;
    }
    return res;
}

void calc() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i % M;
        ifac[i] = power(fact[i], M - 2);
    }
}

signed main() {
    calc();
    int n;
    cin >> n;
    if(n & 1) cout << 0;
    else cout << fact[n] * 1ll * ifac[n/2] % M * ifac[n/2 + 1] % M;
}