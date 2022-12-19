#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<string>> A(k + 2, vector<string> (n));
    for (int i = 1; i <= k + 1; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    
}