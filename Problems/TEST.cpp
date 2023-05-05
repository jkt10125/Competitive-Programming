#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::map<int, int> A;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            A[x]++;
        }

        for (auto &it : A) {
            if (!it.second) continue;
            if (A.find(it.first * k) != A.end()) {
                if (A[it.first * k]) {
                    it.second--;
                    A[it.first * k]--;
                }
            }
        }

        int ans = 0;
        for (auto it : A) {
            ans += it.second;
        }

        std::cout << ans << std::endl;
    }
}