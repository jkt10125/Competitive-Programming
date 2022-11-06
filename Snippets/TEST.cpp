#include <bits/stdc++.h>
using namespace std;
std::vector<std::array<int, 2>> divisors(int n) {
    std::vector<int> p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        p.push_back(n);
    }
    
    n = p.size();
    std::vector<std::array<int, 2>> a(1 << n);
    a[0] = {1, 1};
    for (int i = 1; i < (1 << n); i++) {
        int j = __builtin_ctz(i);
        auto [x, y] = a[i ^ (1 << j)];
        a[i] = {x * p[j], -y};
    }
    return a;
}

vector<int> factors(int n) {
    vector<int> A;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            A.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> incr = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (int d = 7; d * d <= n; d += incr[i++]) {
        while (n % d == 0) {
            A.push_back(d);
            n /= d;
        }
        if(i == 8) i = 0;
    }
    if(n > 1) A.push_back(n);
    return A;
}

int main() {
	auto d = trial_division3(420);
	for(auto it : d) {
		// for(auto i : it) {
		// 	cout << i << ' ';
		// }
		cout << it << ' ';
		cout << endl;
	}
}