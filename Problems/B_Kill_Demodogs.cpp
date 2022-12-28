/*
** Date: 27/12/2022 | Time: 20:11:26
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1000000007;

int power(int a, int b) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		pow %= mod, a %= mod;
	}
	return pow;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ans = n * (n + 1) % mod * (2*n + 1) % mod * power(3, mod - 2) % mod;
        int a = n * n % mod;
        int b = n * (n - 1) % mod * power(2, mod - 2) % mod;
        cout << (ans - a + b + mod) * 2022 % mod << endl;
    }
}