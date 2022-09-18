#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n, p, q, r;
	cin >> n >> p >> q >> r;
	vector<int> A(n+1);
	for(int i=1; i<=n; i++) cin >> A[i];
	vector<int> psum(n+1, 0);
	for(int i=1; i<=n; i++) {
		psum[i] += psum[i-1] + A[i];
	}


	bool f = 0;
	for(int i=1; i<=n; i++) {
		auto j = lower_bound(psum.begin(), psum.end(), psum[i-1] + p);
		if(j == psum.end()) continue;
		int J = j - psum.begin();
		if(psum[J] != psum[i-1] + p) continue;

		auto k = lower_bound(psum.begin(), psum.end(), psum[J] + q);
		if(k == psum.end()) continue;
		int K = k - psum.begin();
		if(psum[K] != psum[J] + q) continue;

		auto l = lower_bound(psum.begin(), psum.end(), psum[K] + r);
		if(l == psum.end()) continue;
		int L = l - psum.begin();
		if(psum[L] != psum[K] + r) continue;
		
		else {f = 1; break;}
	}

	if(f) cout<<"Yes";
	else cout<<"No";
}