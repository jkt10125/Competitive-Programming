#include <bits/stdc++.h>
using namespace std;

#define x64 long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<x64> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        
        sort(A.begin(), A.end());
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1]) {
                ok = false;
                break;
            }
        }

        if (ok) {

            for (int i = 2; i <= n / 2; i++) {
                vector<int> hsh(i);
                for (x64 j : A) {
                    hsh[j % i]++;
                }
                if (*min_element(hsh.begin(), hsh.end()) > 1) {
                    ok = false;
                    break;
                }
            }

        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}