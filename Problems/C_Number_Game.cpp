#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) {
            std::cin >> A[i];
        }

        auto f = [&A] (int k) {
            int n = A.size();
            std::multiset<int> s(A.begin(), A.end());
            for (int i = 1; i <= k; i++) {
                auto it = s.upper_bound(k - i + 1);
                if (it == s.begin()) return false;
                it--;
                s.erase(it);
                if (s.empty()) return (i == k);
                s.erase(s.begin());
                s.insert(n + i);
            }
            return true;
        };  

        int l = 0, r = n + 1;
        int ans;
        while (l <= r) {
            int m = (l + r) / 2;
            if (f(m)) {
                ans = m; l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        std::cout << ans << std::endl;
    }
}