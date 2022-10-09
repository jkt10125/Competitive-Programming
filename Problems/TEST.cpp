#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 61, mod = 998244353;

int A[2];
vector<int> fact, ifact;

int power(int a, int b, int mod) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		pow %= mod, a %= mod;
	}
	return pow;
}

void init() {
	fact.assign(N+1, 1);
	ifact.assign(N+1, 1);
	for(int i=1; i<=N; i++) {
		fact[i] = fact[i-1] * i % mod;
		ifact[i] = power(fact[i], mod-2, mod);
	}
}

void f(int n, int turn = 0) { // turn = 0 means alice turn
	if(n == 0) return;
	A[turn] += (fact[n] * ifact[2] % mod) * (ifact[(n>>1)] * ifact[(n>>1)] % mod);
	if((n >> 1) >= 2)
		A[1-turn] += fact[n-2] * (ifact[(n>>1)-2] * ifact[(n>>1)] % mod);
	A[turn] %= mod;
	A[1-turn] %= mod;
	f(n-2, 1-turn);
}

signed main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		A[0] = A[1] = 0;
		int n;
		cin >> n;
		f(n);
		cout<<A[0]<<" "<<A[1]<<" "<<1<<endl;
	}
}