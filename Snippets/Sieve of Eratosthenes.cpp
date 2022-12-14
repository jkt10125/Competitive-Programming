// TC : O(nloglog(n))
// vector<bool> sieve(int n) {
// 	vector<bool> isPrime(n+1, true);
// 	isPrime[0] = isPrime[1] = false;
// 	int ctr = 2;
// 	while(ctr <= n) {
// 		for(int i=(ctr<<1); i<=n; i+=ctr)
// 			isPrime[i] = false;
// 		ctr++;
// 		while(ctr <= n && isPrime[ctr] == false) ctr++;
// 	}
// 	return isPrime;
// }

// TC : O(n) -> gives all the primes less than n
const int N = 2e7;
vector<int> prime; 
int min_prime_factor[N + 1];
// do_once() : sieve()

void sieve () {
	for (int i = 2; i <= N; i++) {
		if (min_prime_factor[i] == 0) { 
			min_prime_factor[i] = i;
			prime.push_back(i); 
		}
		for (int p : prime) {
			if(p > min_prime_factor[i] || i * p > N) break;
			min_prime_factor[i * p] = p;
		}
	}
}

// if (min_prime_factor[x] == x) ==> x is prime