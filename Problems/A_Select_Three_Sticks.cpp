#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> A(n);
		for(int i=0; i<n; i++) cin >> A[i];
		sort(A.begin(), A.end());
		int ans = INT_MAX;
		for(int i=1; i<n-1; i++) {
			ans = min(ans, abs(A[i+1]-A[i])+abs(A[i-1]-A[i]));
		}
		cout<<ans<<endl;
	}
}