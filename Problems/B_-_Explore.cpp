	#include <iostream>
	using namespace std;

	#define int long long

	signed main() {
		int n, m, t;
		cin >> n >> m >> t;
		int A[n];
		for(int i=1; i<n; i++) cin >> A[i];

		int bonus[n+1] = {0};
		for(int i=0; i<m; i++) {
			int x, y;
			cin >> x >> y;
			bonus[x] = y;
		}
		int i;
		for(i=2; i<=n; i++) {
			t -= A[i-1];
			if(t <= 0) break;
			t += bonus[i];
		}
		if(i == n+1) cout<<"Yes";
		else cout<<"No";
	}