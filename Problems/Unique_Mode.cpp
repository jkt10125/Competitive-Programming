/*
** Date: 28/12/2022 | Time: 23:35:56
** Written By: JKT
*/


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

        auto f = [&n, &A] (int freq) {
            map<int, int> m;
            int e;
            int ans = 0;
            int l = 0, r = 0;
            while (r < n) {
                if(m[e] == freq) break;
                if (++m[A[r++]] > m[e]) {
                    e = A[r - 1];
                }
            }
            if (r == n) return 0;
            ans++;
            while (r < n) {
                while (r < n && ++m[A[r++]] < m[e]) {
                    ans++;
                }
                if (r == n) break;
                do {
                    --m[A[l++]];
                } while (A[l - 1] != e && A[l - 1] != A[r - 1]);
                ans++;
                e = A[r - 1];
            }
            return ans;
        };

        cout << f(3) << endl;
    }
}