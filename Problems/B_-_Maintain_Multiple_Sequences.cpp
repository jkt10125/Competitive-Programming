#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> A(n+1);
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        A[i+1].resize(k+1);

        for(int j=1; j<=k; j++) cin >> A[i+1][j];
    }

    while(q--) {
        int s, t;
        cin >> s >> t;
        cout<<A[s][t]<<endl;
    }
}