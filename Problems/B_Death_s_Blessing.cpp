#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long x = 0, mn = INT_MIN;
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            x += a;
        }
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            x += a;
            mn = std::max(a, mn);
        }
        std::cout << x - mn << std::endl;
    }
}