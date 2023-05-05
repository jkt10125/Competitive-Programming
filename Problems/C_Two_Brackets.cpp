#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;

        int c = 0, C = 0, ans = 0;
        for (char cc : s) {
            if (cc == '(') c++;
            if (cc == '[') C++;
            if (cc == ')' && c) ans++, c--;
            if (cc == ']' && C) ans++, C--;
        }

        std::cout << ans << std::endl;
    }
}