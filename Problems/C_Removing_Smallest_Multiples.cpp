#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		vector<int> A(n+1, 1);
		for(int i=0; i<n; i++) {
			if(s[i] == '0') {
				for(int j=i+1; j<=n; j+=(i+1)) {
					if(s[j-1]=='0' && A[j]) {
						ans += i+1;
						A[j] = false;
					}
					if(s[j-1] == '1') break;
				}
			}
		}
		cout<<ans<<endl;
	}
}