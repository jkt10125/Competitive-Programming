#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> A(k+1);
	for(int i=0; i<k; i++) cin >> A[i+1];

	vector<vector<int>> dp(n+1, vector<int> (k+1, INT_MIN));
	for(int i=1; i<=k; i++) dp[0][i] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			if(i < A[j]) dp[i][j] = dp[i][j-1];
			else if(i >= 2*A[j]) dp[i][j] = dp[i - 2*A[j]][j];
			else {
				dp[i][j] = max(-dp[i-A[j]][j] + A[j], dp[i][j-1]);
			}
		}
	} 
	// int ctr = 0;
	// for(auto it : dp) {
	// 	cout<<ctr++<<" : ";
	// 	for(auto iit : it) cout<<iit<<" ";
	// 	cout<<endl;
	// }
	assert((dp[n][k] + n) % 2 == 0);
	cout << (dp[n][k] + n) / 2;
}