#include <bits/stdc++.h>
using namespace std;
#define int long long
int ask(int a, int b) {
	cout<<"? "<<a<<" "<<b<<endl;
	int x;
	cin >> x;
	return x;
}

void print(int n) {
	cout<<"! "<<n<<endl;
}

signed main() {
	int n = 2;
	while(true) {
		int x = ask(1, n);
		if(x == -1) {
			print(n-1);
			return 0;
		}
		int y = ask(n, 1);
		if(x != y) {
			print(x+y);
			return 0;
		}
		n++;
	}
	return 0;
}