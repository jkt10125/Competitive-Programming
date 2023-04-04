#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        int ctr = 0;

        char c = 'z' + 1;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (idx == -1 || s[i] <= s[idx]) {
                c = s[i];
                idx = i;
            }
        }

        std::cout << s[idx] + s.substr(0, idx) + s.substr(idx + 1) << std::endl;
    }
}