#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(k);
    for (int i = 0; i < k; i++) {
        cin >> A[i];
    }

    vector<bool> dp(n+1, false);

    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (int j = 0; j < k; j++) {
            if (A[j] > i) continue;
            if (!dp[i - A[j]]) {
                ok = true;
            }
        }
        dp[i] = ok;
    }

    for (int i = 0; i < n; i++) {
        if (dp[i + 1]) cout << 'W';
        else cout << 'L';
    }
}