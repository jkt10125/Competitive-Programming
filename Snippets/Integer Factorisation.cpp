#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> prime; 
// do_once() : sieve(N)

void sieve (int n) {
	vector<int> min_prime_factor (n + 1, 0);
	for (int i = 2; i <= n; i++) {
		if (min_prime_factor[i] == 0) { 
			min_prime_factor[i] = i;
			prime.push_back(i); 
		}
		for (int p : prime) {
			if(p > min_prime_factor[i] || i * p > n) break;
			min_prime_factor[i * p] = p;
		}
	}
}

vector<array<int, 2>> factor (int n) {
    vector<array<int, 2>> p;
    for (int i : prime) {
        if (i * i > n) break;
        if (n % i == 0) {
            p.push_back({i, 0});
            while (n % i == 0) {
                n /= i;
                p.back()[1]++;
            }
        }
    }
    if (n > 1) {
        p.push_back({n, 1});
    }

    return p;
}

//NOTE: If the function is called less number of times then directly use the 
//  sqrt n method else calculate the primes first and then iterate over primes only!

vector<array<int, 2>> factor (int n) {
    vector<array<int, 2>> p;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            p.push_back({i, 0});
            while(n % i == 0) {
                n /= i;
                p.back()[1]++;
            }
        }
    }
    if (n > 1) {
        p.push_back({n, 1});
    }
    return p;
}

// function to find ETF of n
int phi (int n) {
    int ans = n;
    for(auto [i, x] : factor(n)) {
        ans = ans - (ans / i);
    }
    return ans;
}

// below code is extremely helpful in applying inclusion-exclusion principle
vector<array<int, 2>> divisors (int n) {
    vector<int> p;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            p.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if (n > 1) p.push_back(n);
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