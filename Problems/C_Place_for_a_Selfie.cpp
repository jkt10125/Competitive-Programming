#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::cerr << n << " " << m << std::endl;

        std::set<int> s;

        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            s.insert(x);
        }

        while (m--) {
            int a, b, c;
            std::cin >> a >> b >> c;

            if (c <= 0) {
                std::cout << "NO" << std::endl;
                continue;
            }

            int D = b * b - 4 * a * c;

            if (D <= 0) {


                int m = sqrt(4 * a * c);
                int in = b - m;
                int out = b + m;

                auto it = s.upper_bound(in);
                if (it != s.begin()) it--;
                if (it == s.end()) {
                    it = s.upper_bound(out);
                }

                if (it == s.end()) {
                    std::cout << "NO" << std::endl;
                    continue;
                }
                else {
                    std::cout << "YES" << std::endl << *it << std::endl;
                }

                std::cerr << "in: " << in << " out: " << out << std::endl;
            }
            else {
                int m = ceil(sqrt(4 * a * c));
                int in = b - m;
                int out = b + m;

                auto it = s.lower_bound(in);
                if (it != s.end() && *it <= out) {
                    std::cout << "YES" << std::endl << *it << std::endl;
                } else {
                    std::cout << "NO" << std::endl;
                }
            }
        }
        std::cout << std::endl;
    }
}