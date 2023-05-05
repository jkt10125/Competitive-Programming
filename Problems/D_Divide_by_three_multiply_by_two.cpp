#include <bits/stdc++.h>

#define x64 long long

int f(x64 n, int k) {
    int ctr = 0;
    while (n % k == 0) n /= k, ctr++;
    return ctr;
}

bool cmp(x64 a, x64 b) {
    return f(a, 3) > f(b, 3) ? true : f(a, 2) < f(b, 2);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<x64> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    sort(A.begin(), A.end(), cmp);
    for (x64 it : A) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
    return 0;
}