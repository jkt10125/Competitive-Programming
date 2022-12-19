#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> A(m);
        for (int i = 0; i < m; i++) {
            cin >> A[i];
        }

        if (*max_element(A.begin(), A.end()) <= (n / k + (n % k != 0))) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}