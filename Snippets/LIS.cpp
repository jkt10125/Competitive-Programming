#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n], dp[n] = {1};
	for(int i=0; i<n; i++) cin >> A[i];

	vector<int> tmp(1, 0);
	for(int i=1; i<n; i++) {
		int idx = tmp.size();
		int l = 0, r = idx - 1;
		while(l <= r) {
			int m = (l + r) / 2;
			if(A[tmp[m]] >= A[i]) idx = m, r = m - 1;
			else l = m + 1;
		}

		dp[i] = (idx == 0) ? 1 : dp[tmp[idx-1]] + 1;
		if(idx != tmp.size()) tmp[idx] = i;
		else tmp.push_back(i);
	}
	for(int i : dp) cout<<i<<" ";
}