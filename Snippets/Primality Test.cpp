// TC : O(sqrt(n))
bool isPrime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

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

bool isPrime (int n) {
	for(int i : prime) {
		if (i * i > n) break;
		if (n % i == 0) return false;
	}
	return true;
}