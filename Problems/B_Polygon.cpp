/*
** Date: 27/12/2022 | Time: 11:40:25
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
        vector<string> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (A[i][j] == '1') {
                    if (A[i + 1][j] == '0' && A[i][j + 1] == '0') {
                        ok = false;
                        break;
                    }
                }
            }
        }

        const string out[] = {"NO", "YES"};
        cout << out[ok] << endl;
    }
}