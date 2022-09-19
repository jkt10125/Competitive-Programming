#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		bool a = true;
		if(s[0] == '?') s[0] = 'U';
		for(int i=1; i<s.size(); i++) {
			if(s[i] == '?') {
				if(s[i-1] == 'U') {
					s[i] = 'U';
				}
				else s[i] = 'M';
			}

			if(s[i] == 'U' && s[i-1] == 'M') { a = false; break; }
		}

		if(a) cout<<"No\n";
		else cout<<"Yes\n";
	}
}