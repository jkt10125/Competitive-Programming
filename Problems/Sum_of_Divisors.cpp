#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> factor(int n) {
    vector<array<int, 2>> A;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            A.push_back({i, 0});
            while (n % i == 0) {
                n /= i;
                A.back()[1]++;
            }
        }
    }
    if (n > 1) {
        A.push_back({n, 1});
    }
    return A;
}

const int m = 1000000007;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    auto A = factor(n);
    int ans = 1;
    for (auto [x, y] : A) {
        cerr << x << y << endl;
        int var = power(x, y + 1);
        var = (var + m - 1) % m;
        cerr << var << endl;
        var = var * power(x - 1, m - 2) % m;
        ans = (ans * var) % m;
    }

    cout << ans;
}