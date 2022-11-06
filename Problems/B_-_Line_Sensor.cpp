#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    for(int j=0; j<m; j++) {
        int ctr = 0;
        for(int i=0; i<n; i++) {
            ctr += (A[i][j] == '#');
        }
        cout << ctr << " ";
    }
}