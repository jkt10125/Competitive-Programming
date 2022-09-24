#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        for(int j=0; j<m; j++) {
            for(int i=n-1; i>0; i--) {
                if(A[i][j] == '.');
            }
        }
    }
}