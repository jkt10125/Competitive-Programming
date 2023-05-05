#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) {
            std::cin >> A[i];
        }

        bool ok = true;
        for (int i = 0; i < n / 2; i++) {
            if (A[i] != A[n - i - 1]) {
                ok = false;
                break;
            }
        }

        if (ok) std::cout << 0;
        else {
            int ans = 0;
            for (int i = 0; i < n / 2; i++) {
                ans = std::__gcd(ans, abs(A[i] - A[n - i - 1]));
            }

            std::cout << ans;
        }

        std::cout << std::endl;
    }
}