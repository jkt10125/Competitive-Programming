#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
const int N = 2e6;
vector<int> fib;
// do_once() : fib_seq(N)

void fib_seq(int n, int mod=0) {
	fib.resize(n+1, 0);
	fib[0] = 0; fib[1] = 1;
	for(int i=2; i<=n; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		if(mod) fib[i] %= mod;
	}
}

// TC : O(logn)
array<int, 2> fibo(int n, int mod = 0) { // returns {fib[n], fib[n + 1]}
    if (n == 0) return {0, 1};
    array<int, 2> p = fibo(n >> 1);
    int c = p[0] * (2 * p[1] - p[0]);
    int d = p[0] * p[0] + p[1] * p[1];
	if(mod) c %= mod, d %= mod;
    if (n & 1) return {d, c + d};
    else return {c, d};
}
