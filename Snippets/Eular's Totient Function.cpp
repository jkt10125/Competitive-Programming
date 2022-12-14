#include <bits/stdc++.h>
using namespace std;
// TC : O(sqrt(n))

int phi(int n) {
	int ans = n;
	for(int i=2; i*i<=n; i++) {
		if(n % i == 0) {
			ans -= ans / i;
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) ans -= ans / n;
	return ans;
}

// TC : O(nloglog(n))
vector<int> Totient_Function(int n) {
	vector<int> phi(n+1, 0);
	for(int i=1; i<=n; i++) phi[i] = i;
	for(int i=2; i<=n; i++) {
		if(phi[i] == i) {
			for(int j=i; j<=n; j++) phi[j] -= phi[j] / i;
		}
	}
	return phi;
}