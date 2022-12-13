#include <bits/stdc++.h>
using namespace std;

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


vector<array<int, 2>> factor (int n) {
    vector<array<int, 2>> p;
    if (n > N) { // O(sqrt(n / log n))
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
    }
    else { // O(log n)
        while (n > 1) {
            if (p.empty() || p.back()[0] != min_prime_factor[n]) {
                p.push_back({min_prime_factor[n], 0});
            }
            n /= min_prime_factor[n];
            p.back()[1]++;
        }
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans;
        if (__gcd(a, b) != 1) {
            ans = 0;
        }
        else {
            int diff = b - a;
            if (diff == 1) {
                ans = -1;
            }
            else {
                auto A = factor(diff);
                ans = INT_MAX;
                for (auto [i, j] : A) {
                    ans = min (ans, i - a % i);
                }    
            }
        }

        cout << ans << endl;
    }
}