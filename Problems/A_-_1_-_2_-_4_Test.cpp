#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int A[5] = {0};
	while(a) {
		if(a >= 4) A[4]++, a -= 4;
		else if(a >= 2) A[2]++, a -= 2;
		else if(a >= 1) A[1]++, a -= 1;
	}
	while(b) {
		if(b >= 4) A[4]++, b -= 4;
		else if(b >= 2) A[2]++, b -= 2;
		else if(b >= 1) A[1]++, b -= 1;
	}
	int c = 0;
	for(int i=0; i<5; i++) {
		if(A[i]) c += i;
	}
	cout<<c;
}