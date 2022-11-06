// TC : O(sqrt(n))
vector<pair<int, int>> factors(int n) {
	vector<pair<int, int>> factor(1);
	for(int i=2; i*i <= n; i++) {
		while(n % i == 0) {
			if(factor.back().first == i) factor.back().second++;
			else factor.push_back({i, 1});
			n /= i;
		}
	}
	if(n > 1) factor.push_back({n, 1});
	return factor;
}


// TC : O(sqrt(n)) : MORE OPTIMISED
vector<int> factors(int n) {
    vector<int> A;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            A.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> incr = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (int d = 7; d * d <= n; d += incr[i++]) {
        while (n % d == 0) {
            A.push_back(d);
            n /= d;
        }
        if(i == 8) i = 0;
    }
    if(n > 1) A.push_back(n);
    return A;
}

// below code is extremely helpful in applying inclusion-exclusion principle
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

int f(int a, int m) { // TC : sqrt(a)
    // for 1 <= x <= m
    // return #(gcd(a, x) = 1)
    int ans = 0;
    for(auto [x, y] : divisors(a)) {
        ans += y * (m / x);
    }
    return ans;
}

// NOTE : we can actually reduce the stress on the machine if we have multiple same values
// by maintaining a hash_map of vectors