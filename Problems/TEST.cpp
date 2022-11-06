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

int main() {
    auto d = divisors(420 * 11);
    for(auto it : d) {
        for(auto i : it) cout << i << ' ';
        cout << endl;
    }
}