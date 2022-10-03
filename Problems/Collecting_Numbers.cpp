#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n+1] = {0};
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		A[x] = i;
	}

	int ctr = 1;
	for(int i=1; i<n; i++) {
		if(A[i] > A[i+1]) ctr++;
	}
	cout<<ctr;
}