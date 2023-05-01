#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> A(n, std::vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> A[i][j];
            }
        }

        auto f = [&A, &n, &m] (int l) {
            std::vector<std::vector<int>> dp(n, std::vector<int> (m));

            for (int i = 0; i < n; i++) {
                dp[i][0] = (A[i][0] >= l);
            }
            for (int j = 0; j < m; j++) {
                dp[0][j] = (A[0][j] >= l);
            }

            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (A[i][j] >= l) {
                        dp[i][j] = std::min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
                    }
                    else dp[i][j] = 0;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dp[i][j] >= l) return true;
                }
            }

            return false;
        };

        int l = 1, r = 1000000;
        int ans = 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (f(m)) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        std::cout << ans << std::endl;
    }
}