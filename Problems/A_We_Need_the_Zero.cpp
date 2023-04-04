#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int x, XOR = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> x;
            XOR ^= x;
        }

        if (n & 1) std::cout << XOR << std::endl;
        else if (!XOR) std::cout << 0 << std::endl;
        else std::cout << -1 << std::endl;
    }   
}