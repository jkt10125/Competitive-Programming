#include <bits/stdc++.h>

std::vector<int> prime; 
std::vector<int> min_prime_factor;

void sieve (int n) {
    min_prime_factor.resize(n + 1, 0);
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

bool f(int n, int m) {
    if (m == 1) return true;
    if (min_prime_factor[n] <= m) return false;
    int k = n / m + 1;
    int freq = n / k;
    return f(n, freq);
}

int main() {
    sieve(1000001);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        if (n == 1) std::cout << "YES\n";
        else {
            if (m >= n) std::cout << "NO\n";
            else {    
                if (std::binary_search(prime.begin(), prime.end(), n)) {
                    std::cout << "YES\n";
                }
                else {
                    if (f(n, m)) std::cout << "YES\n";
                    else std::cout << "NO\n";
                }
            }
        }
    }
}