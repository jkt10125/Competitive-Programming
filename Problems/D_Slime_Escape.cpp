#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> A(n+1);
		for(int i=0; i<n; i++) cin >> A[i];
		int mxl = k, mxr = k, sum = k;
		int l = k-1, r = k+1, ctr = 1;
		int tl = 0, tr = 0;
		bool ans = true;
		while(l > 0 && r <= n) {
			cerr<<l<<" "<<r<<endl;
			if(ctr) {
				if(sum + A[r] < 0) {
					if(!ans) break;
					tr = mxr - sum;
					sum = mxr + tl;
					ctr = 0;
					ans = false;
				}
				else {
					ans = true;
					sum += A[r++];
					mxr = max(mxr, sum);
				}
			}
			else {
				if(sum + A[l] < 0) {
					if(!ans) break;
					tl = mxl - sum;
					sum = mxl + tr;
					ctr = 1;
					ans = false;
				}
				else {
					ans = true;
					sum += A[l--];
					mxl = max(mxl, sum);
				}
			}
		}
		cerr<<endl;
		if(ans) cout<<"TRUE\n";
		else cout<<"NO\n";
	}
}