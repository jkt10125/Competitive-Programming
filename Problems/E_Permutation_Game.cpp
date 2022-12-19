#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n + 1);
        int fp = 0, sp = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= n; i++) {
            if (A[i] == i) {
                fp++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (A[i] == n - i + 1) {
                sp++;
            }
        }

        if ((n + 1) % 2 == 0) {
            int v = (n + 1) / 2;
            if (A[v] == v) {
                fp--;
                sp--;
                n--;
            }
        }



        if (2 * sp > n) cout << "Second\n";
        else if (2 * fp >= n) cout << "First\n";
        else cout << "Tie\n";
    }
}