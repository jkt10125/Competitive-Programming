#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(!b) {
			if(a) while(a-- > -1) cout<<0;
			if(c) while(c-- > -1) cout<<1;
		}
		else {
			for(int i=0; i<=a; i++) cout<<0;
			for(int i=0; i<=c; i++) cout<<1;
			for(int i=0; i<b-1; i++) cout<<(i&1);
		}
		cout<<endl;
	}
}