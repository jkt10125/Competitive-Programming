#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1000000007;

signed main() {
	int n;
	cin >> n;
	int dp[5][n+1];
	for(int i=0; i<=n; i++) {
		dp[0][i] = 0;
		dp[1][i] = 0;
		dp[2][i] = 0;
		dp[3][i] = 0;
		dp[4][i] = 0;
	}

	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[3][1] = 1;
	dp[4][1] = 1;

	for(int i=2; i<=n; i++) {
		dp[0][i] = dp[1][i-1] % mod;
		dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % mod;
		dp[3][i] = (dp[2][i-1] + dp[4][i-1]) % mod;
		dp[4][i] = dp[0][i-1] % mod;
		dp[2][i] = (dp[0][i-1] + dp[1][i-1] + dp[3][i-1] + dp[4][i-1]) % mod;
	}

	cout << dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n] << endl;
}
