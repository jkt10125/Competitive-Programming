#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    bool ok = true;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            // if (i == j) continue;
            if (A[i][j] == 0 || A[i + 1][j] == 0 || A[i][j + 1] == 0 || A[i + 1][j] == 0) continue;
            if (A[i][j] > A[i][j + 1] && A[i + 1][j] < A[i + 1][j + 1]) {
                ok = false;
                break;
            }
            if (A[i][j] < A[i][j + 1] && A[i + 1][j] > A[i + 1][j + 1]) {
                ok = false;
                break;
            }
            if (A[i][j] > A[i + 1][j] && A[i][j + 1] < A[i + 1][j + 1]) {
                ok = false;
                break;
            }
            if (A[i][j] < A[i + 1][j] && A[i][j + 1] > A[i + 1][j + 1]) {
                ok = false;
                break;
            }
        }
    }

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-1; j++) {
            if(A[i][j] == 0) continue;
            for(int k=i+1; k<n; k++) {
                for(int l=j+1; j<m; j++) {
                    if(A[k][l] == 0 || A[k][j] * A[i][l] == 0) continue;
                    if ((A[i][j] - A[i][l]) * (A[k][j] - A[k][l]) < 0) {
                        ok = false;
                        break;
                    }
                    if ((A[i][j] - A[k][j]) * (A[i][l] - A[k][l]) < 0) {
                        ok = false;
                        break;
                    }
                }
            }
        }
    }

    if(ok) cout << "Yes";
    else cout << "No";
}