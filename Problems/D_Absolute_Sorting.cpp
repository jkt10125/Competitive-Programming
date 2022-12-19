#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        

        vector<int> B = A;
        sort(B.begin(), B.end());

        if (A == B) {
            cout << 0 << endl;
        }
        else {
            reverse(B.begin(), B.end());
            if (A == B) {
                cout << *max_element(A.begin(), A.end()) << endl;
            }
            else {
                int l = 0, r = 1000000000;
                for (int i = 0; i < n - 1; i++) {
                    if (A[i] < A[i + 1]) {
                        r = min((A[i] + A[i + 1]) / 2, r);
                    }
                    else if (A[i] > A[i + 1]) {
                        l = max(l, (A[i] + A[i + 1] + 1) / 2);
                    }
                }

                if (l > r) cout << -1 << endl;
                else cout << l << endl;
            }
        }
    }
}