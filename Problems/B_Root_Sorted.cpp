#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] < 2) idx = i;
        }

        bool ok = true;
        for (int i = 1; i <= idx; i++) {
            if (A[i] < A[i - 1]) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}