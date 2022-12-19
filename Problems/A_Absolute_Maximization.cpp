#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        int mx = 0, mn = (1 << 30) - 1;
        for (int i = 0; i < n; i++) {
            mx = mx | A[i];
            mn = mn & A[i];
        }

        cout << mx - mn << endl;
    }
}