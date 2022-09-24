	#include <iostream>
	using namespace std;

	int main() {
		int t;
		cin >> t;
		while(t--) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a = 1-a; b = 1-b; c = 1-c; d = 1-d;
			if(a*b*c*d) cout<<"IN";
			else cout<<"OUT";
			cout<<endl;
		}
	}