#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1) {
			cout<<1<<endl;
			continue;
		}
		if(n == 2) {
			cout<<1<<endl<<"1 1\n";
			continue;
		}
		cout<<1<<endl<<"1 1\n";
		for(int i=3; i<=n; i++) {
			cout<<1<<" ";
			for(int j=2; j<i; j++) cout<<0<<" ";
			cout<<"1 \n";
		}
	}
}