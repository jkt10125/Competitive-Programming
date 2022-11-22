#include <bits/stdc++.h>
using namespace std;

vector<int> A;

const int N = 1e4;
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

void f() {
    A[1] = 1;
    A[2] = 2;
    A[3] = 3;
    A[4] = 4;
    A[5] = 5;
    A[6] = 6;
    A[7] = 7;
    A[8] = 8;
    A[9] = 9;
    A[10] = 10;
    A[11] = 11;
    A[12] = 12;
    A[13] = 13;
    A[14] = 13;
    A[15] = 13;
    A[16] = 14;
    A[17] = 15;
    A[18] = 14;
    A[19] = 15;
    A[20] = 15;
}

int main() {
    sieve(N);
    int t;
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        cout << "Case #" << _i << ": ";

        int l;
        cin >> l;

        int m = max(l, 20);
        A.assign(m+1, 0);
        f();
        if(l != m) {
            cout << A[l] << endl;
        }
        else {
            for(int i = 21; i <= l; i++) {
                A[i] = A[i-1] + 1;
                for (int j : prime) {
                    if(j * j > i) break;
                    if (i % j == 0) {
                        A[i] = min(A[i], A[i / j] + 4 + 2 * (j - 1));
                    }
                }
            }
            cout << A[l] << endl;
        }
    }
}