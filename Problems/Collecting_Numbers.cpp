#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n];
	for(int i=0; i<n; i++) cin >> A[i];
	set<int> S;
	S.insert(A[0]);
	for(int i=1; i<n; i++) {
		auto it = S.upper_bound(A[i]);
		if(it == S.begin()) S.insert(A[i]);
		else {
			S.erase(--it);
			S.insert(A[i]);
		}
	}
	cout<<S.size();
}