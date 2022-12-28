#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int num[N + 1];


vector<int> f(int n) {
    // 1 <= x < y <= n
    // #(gcd(x, y) = k)
    vector<int> dp(n + 1);
    for (int i = n; i > 0; i--) {
        int a = n / i;
        dp[i] = a * (a - 1) / 2;
        for (int j = i + i; j <= n; j += i) {
            dp[i] -= dp[j];
        }
    }
    return dp;
}

int main() {
    int n;
    cin >> n;

}