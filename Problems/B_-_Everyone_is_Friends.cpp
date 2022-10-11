#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(m+1, vector<int> (n+1, 0));
    for(int i=1; i<=m; i++) {
        int k;
        cin >> k;
        while(k--) {
            int x;
            cin >> x;
            A[i][x] = 1;
        }
    }

    int ans = 1;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int ok = false;
            for(int k=1; k<=m; k++) {
                if(A[k][i] && A[k][j]) ok = true;
            }
            if(!ok) ans = false;
        }
    }

    if(ans) cout<<"Yes";
    else cout<<"No";
}