#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n+1, vector<int> (n+1));
        for(int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            A[x][y]++;
        }
        if(m >= n) cout << "NO\n";
        else {
            bool ok = true;
            bool ok2 = true;
            for(int i=1; i<=n; i++) {
                int ctr = 0;
                for(int j=1; j<=n; j++) {
                    ctr += A[i][j];
                }
                if(ctr > 1) {
                    if(!ok) ok2 = false;
                    else ok = false;
                }
            }

            for(int j=1; j<=n; j++) {
                int ctr = 0;
                for(int i=1; j<=n; j++) {
                    ctr += A[i][j];
                }
                if(ctr > 1) {
                    if(!ok) ok2 = false;
                    else ok = false;
                }
            }

            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}