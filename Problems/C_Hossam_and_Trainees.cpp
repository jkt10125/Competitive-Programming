#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> prime;
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

bool ok;
map<int, int> hsh;

void f(int n) {
    if(ok) return;
    for (int i : prime) {
        if (i * i > n) break;
        if (n % i == 0) {
            if(hsh[i]) {
                ok = true;
                return;
            }
            hsh[i]++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        if (hsh[n]) {
            ok = true;
            return;
        }
        hsh[n]++;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(100002);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }

        ok = false;
        hsh.clear();
        for (int i = 0; i < n; i++) {
            f(A[i]);
        }
        if(ok) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}