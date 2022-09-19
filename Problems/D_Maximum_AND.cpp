#include <bits/stdc++.h>
using namespace std;
int n, ans;

void solve(vector<int> &A, vector<int> &B, int l, int r, int e) {
	if(e < 0 || l >= r) return;
	vector<int> cA, cB;
	for(int i=l; i<=r; i++) {
		if(A[i] & (1 << e)) cA.push_back(i);
		if(B[i] & (1 << e)) cB.push_back(i);
	}
	int a = cA.size();
	if(cA.size() + cB.size() != r-l+1) {
		ans = ans & ~(1 << e);
		solve(A, B, l, r, e-1);
	}
	else {
		for(int i=l; i<=r; i++) {
			if(cA.empty()) break;
			if(!(A[i] & (1 << e))) {
				swap(A[i], A[cA.back()]);
				cA.pop_back();
			}
		}
		for(int i=r; i>=l; i--) {
			if(cB.empty()) break;
			if(!(B[i] & (1 << e))) {
				swap(B[i], B[cB.back()]);
				cB.pop_back();
			}
		}
		solve(A, B, l, l+a-1, e-1);
		solve(A, B, l+a, r, e-1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> A(n), B(n);
		for(int i=0; i<n; i++) cin >> A[i];
		for(int i=0; i<n; i++) cin >> B[i];

		ans = (1 << 30) - 1;
		solve(A, B, 0, n-1, 29);
		cout << ans << endl;
	}
}