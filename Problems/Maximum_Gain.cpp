#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int t=1; t<=tc; t++) {
        cout<<"Case #"<<t<<": ";
        
        int n, m;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        cin >> m;
        vector<int> B(m);
        for(int i=0; i<m; i++) cin >> B[i];

        int k;
        cin >> k;

            
    }
}



    // vvll dp(n, vll(n, 0));
	// F0R(i, n) dp[i][i] = A[i];
	// F0R(j, n) {
	// 	FOR(i, j-1, 0, -1) {
	// 		dp[i][j] = MAX(A[i]-dp[i+1][j], A[j]-dp[i][j-1]);
	// 	}
	// }
	// cout<<dp[0][n-1];