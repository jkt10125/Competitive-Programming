#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            A[i] -= i;
        }

        sort(A.begin(), A.end());

        int ans = 0, prev_ans = 0;
        int curr = x;
        bool ok = false;
        while (curr < y) {
            int idx = upper_bound(A.begin(), A.end(), curr) - A.begin();
            curr += idx - (n - idx);
            if (curr <= x) {
                ans = -1;
                break;
            }
            if (curr - x == n) {
                ok = true;
                
            }
            x = curr;
            prev_ans = ans;
            ans += n;
        }
    }
}