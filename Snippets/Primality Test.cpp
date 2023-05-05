#include <vector>

std::vector<int> spf, prime;

// O(n)
void sieve(int n) {
	spf.assign(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		if (!spf[i]) { spf[i] = i; prime.push_back(i); }
		for (int p : prime) { if (p > spf[i] || i * p > n) break; spf[i * p] = p; }
	}
}

// prime must contain primes atleast upto sqrt(n)
bool isPrime (int n) {
	if (n < spf.size()) return (spf[n] == n);
	for(int i : prime) { if (i * i > n) break; if (n % i == 0) return false; } return true;
}