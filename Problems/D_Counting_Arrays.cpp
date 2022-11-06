#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 300100;
const int mod = 998244353;

vector<int> prime;

void SIEVE() {
	vector<int> min_prime_factor(N + 1, 0);
	for(int i=2; i<=N; i++) {
		if(min_prime_factor[i] == 0) { 
			min_prime_factor[i] = i;
			prime.push_back(i); 
		}
		for(int p : prime) {
			if(p > min_prime_factor[i] || i * p > N) break;
			min_prime_factor[i * p] = p;
		}
	}
}

int power(int a, int b) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		pow %= mod, a %= mod;
	}
	return pow;
}

signed main() {
    SIEVE();
    int n, m;
    cin >> n >> m;
    vector<int> dp(n+1, 0);
    dp[1] = m % mod;
    int num = 1;
    for(int i=2; i<=n; i++) {
        int p = *lower_bound(prime.begin(), prime.end(), i);
        if(p == i) num = num * i;
        if(num > m) break;
        dp[i] = dp[i-1] * (m / num % mod) % mod;
    }

    int sum = 0; m %= mod;
    for(int i=1; i<=n; i++) {
        sum += power(m, i) - dp[i] + mod;
        sum %= mod;
    }
    cout << sum << endl;

}