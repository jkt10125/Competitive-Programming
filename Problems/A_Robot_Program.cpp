#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        if (x > y) std::swap(x, y);

        std::cout << 2 * x + std::max(2 * (y - x) - 1, 0) << std::endl;
    }
}