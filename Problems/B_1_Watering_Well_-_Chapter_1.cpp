#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;

signed main() {
	int t;
	cin >> t;
	for(int _i=1; _i<=t; _i++) {
		int n;
		cin >> n;
		int sx=0, ssx=0, sy=0, ssy=0;
		for(int i=0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			sx += x;
			sy += y;
			ssx += x * x;
			ssy += y * y;
			sx %= mod; sy %= mod;
			ssx %= mod; ssy %= mod;
		}
		int sum = 0;
		int q;
		cin >> q;
		while(q--) {
			int x, y;
			cin >> x >> y;
			sum += n * (x * x % mod + y * y % mod) % mod + ssx + ssy - 2 * (x * sx % mod + y * sy % mod) % mod;
			sum %= mod;
		}

		cout<<"Case #"<<_i<<": "<<sum<<endl;
	}
}