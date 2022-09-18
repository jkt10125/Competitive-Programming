#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;
int power(int a, int b, int mod=0) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		if(mod) pow %= mod, a %= mod;
	}
	return pow;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int a, n;
        cin >> a >> n;

        cout<<power(a, n/2, mod)<<endl;
    }
}