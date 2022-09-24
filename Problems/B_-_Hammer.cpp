#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if(x > 0) {
		if(x < y || y < 0) cout<<x;
		else {
			if(z > y) cout<<-1;
			else {
				if(z < 0) cout<<x - 2*z;
				else cout<<x;
			}
		}
	}
	else {
		if(x > y || y > 0) cout<<-x;
		else {
			if(z < y) cout<<-1;
			else {
				if(z > 0) cout<<2*z-x;
				else cout<<-x;
			}
		}
	}
}