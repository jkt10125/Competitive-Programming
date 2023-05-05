#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<std::string, int> M;
    for (int i = 0; i < n - 1; i++) {
        M[s.substr(i, 2)]++;
    }
    int ans = 0;
    for (auto it : M) {
        if (ans < it.second) {
            s = it.first;
            ans = it.second;
        }
    }

    std::cout << s << std::endl;
    return 0;
}