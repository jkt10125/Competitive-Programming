#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(n + 1);
    std::map<int, int> HASH;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[HASH[A[i] - 1]] + 1;
        if (dp[i] > dp[HASH[A[i]]]) HASH[A[i]] = i;
    }

    std::vector<int> ans;
    int idx = std::max_element(dp.begin(), dp.end()) - dp.begin();
    int val = A[idx];
    
    for (int i = idx; i > 0; i--) {
        if (A[i] == val) {
            val--;
            ans.push_back(i);
        }
    }

    std::cout << ans.size() << std::endl;
    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        std::cout << *it << ' ';
    }

    std::cout << std::endl;
    return 0;
}