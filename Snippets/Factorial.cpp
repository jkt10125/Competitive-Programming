// TC : O(n)
// Generates all factorials from 1 to n

const int N = 2e5;
vector<int> fac;
vector<int> ifac;
// do_once() : fact(N)

int power(int a, int b, int mod=0) {
	int pow = 1;
	while (b > 0) {
		if (b & 1) pow *= a;
		b = b >> 1;	a *= a;
		if(mod) pow %= mod, a %= mod;
	}
	return pow;
}

void fact (int n, int mod = 0) {
	fac.resize(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i;
		if (mod) fac[i] %= mod;
	}
	
	ifac.resize(n + 1);
	for(int i = 2; i <= n; i++) {
		ifac[i] = power(fac[i], mod - 2, mod);
	}
}