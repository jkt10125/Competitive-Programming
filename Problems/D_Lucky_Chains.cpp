#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector<int> prime; 
int min_prime_factor[N + 1];

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

vector<int> get_factors (int n) {
    vector<int> A;
    while (n > 1) {
        if (A.empty() || A.back() != min_prime_factor[n]) {
            A.push_back(min_prime_factor[n]);
        }
        n /= min_prime_factor[n];
    }
    return A;
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
                vector<int> A = get_factors(diff);
                ans = INT_MAX;
                for (int i : A) {
                    ans = min (ans, i - a % i);
                }    
            }
        }

        cout << ans << endl;
    }
}