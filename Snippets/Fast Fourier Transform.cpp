#include <bits/stdc++.h>

using namespace std;

#define int long long

/* PARTS OF CODE for fft taken from https://cp-algorithms.com/algebra/fft.html */

const int mod = 998244353;
const int root = 15311432; // which is basically 3 ^ 119 % mod
const int root_1 = 469870224;
const int root_pw = (1 << 23);

int power(int a, int b, int mod=0) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		if(mod) pow %= mod, a %= mod;
	}
	return pow;
}

inline int inverse(int a) { // returns the modular inverse of 
	return power(a % mod, mod - 2, mod);
}

// code for fft in O(nlogn)
void fft(vector<int>& a, bool invert) {
	int n = a.size();

	/// this does the bit inversion 
	for(int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}

	for(int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? root_1: root;
		for(int i = len; i < root_pw; i <<= 1) {
			wlen = wlen * wlen % mod;
		}
		for(int i = 0; i < n; i += len) {
			int w = 1;
			for(int j = 0; j < len / 2; ++j) {
				int u = a[i + j], v = a[i + j + len / 2] * w % mod;
				a[i + j] = u + v < mod ? u + v : u + v - mod;
				a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
				w = w * wlen % mod;
			}
		}
	}

	if(invert) {
		int n_1 = inverse(n);
		for(int& x : a){
			x = x * n_1 % mod;
		}
	}
}

// a * b in O(nlogn)
vector<int> multiply(vector<int> const &a, vector<int> const &b) {

	vector<int> fa = a, fb = b;
	int n = 1;
	while(n < (int)a.size() + (int)b.size()) {
		n <<= 1;
	}
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for(int i = 0; i < n; i++) {
		fa[i] = fa[i] * fb[i] % mod;
	}
	fft(fa, true);
	while(fa.size() > 1 && fa.back() == 0) {
		fa.pop_back();
	}

	return fa;
}

/* End of FFT Template */

signed main() {
    vector<int> A = {1, 3, 0, 5};
    vector<int> B = {0, 3, 2, 4};

    // cerr<<A.size();
    vector<int> c = multiply(A, B);
    for(int i=0; i<c.size(); i++) {
        cerr<<i<<" : "<<c[i]<<endl;
    }
}