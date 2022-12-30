#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

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
        int A, B;
        cin >> A >> B;
        B += A;
        int n = (B + 1) / 2;
        cout << n * A % mod * power(B, mod - 2) % mod << endl;
    }
}