// TC : O(n)
vector<int> fibonacci_sequence(int n, int mod=0) {
	vector<int> fib(n+1, 0);
	fib[0] = 0; fib[1] = 1;
	for(int i=2; i<=n; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		if(mod) fib[i] %= mod;
	}
	return fib;
}

// TC : O(logn)
pair<int, int> fib(int n) {
    if (n == 0) return {0, 1};
    pair<int, int> p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1) return {d, c + d};
    else return {c, d};
}
