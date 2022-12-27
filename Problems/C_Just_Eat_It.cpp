/*
** Date: 27/12/2022 | Time: 11:46:37
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

#define x64 long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        x64 sum = accumulate(A, A + n, 0ll);
        x64 b = 0, cb = 0;
        for (int i = 0; i < n - 1; i++) {
            cb += A[i];
            cb = max(cb, 0ll);
            b = max(b, cb);
        }
        if (sum <= b) cout << "NO";
        else {
            b = 0, cb = 0;
            for (int i = 1; i < n; i++) {
                cb += A[i];
                cb = max(cb, 0ll);
                b = max(b, cb);
            }
            if (sum > b) cout << "YES";
            else cout << "NO";
        }
        cout << endl;
    }
}