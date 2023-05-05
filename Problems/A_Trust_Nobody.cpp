#include <bits/stdc++.h>
using namespace std;

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

        sort(A.begin(), A.end());
        
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && A[i] == A[i + 1]) {
                continue;
            }
            if (i < n - 1) {
                if (A[i] <= n - i - 1 && A[i + 1] > n - i - 1)
                    ans = n - i - 1;
            }
            else if (A[i] <= n - i - 1) {
                ans = n - i - 1;
                // break;
            }
        }

        std::cout << ans << std::endl;
    }
}