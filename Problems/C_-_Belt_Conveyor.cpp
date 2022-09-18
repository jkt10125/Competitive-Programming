#include <bits/stdc++.h>
using namespace std;
int n, m;

bool invalid(int x, int y) {
	if(x < 0 || x >= n) return true;
	if(y < 0 || y >= m) return true;
	return false;
}

int main() {
	cin >> n >> m;
	char A[n][m];
	bool B[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> A[i][j];
			B[i][j] = false;
		}
	}

	int x = 0, y = 0, f = 1;
	while(true) {
		if(B[x][y] == true) {f = false; break;}
		B[x][y] = true;
		int a = x, b = y;
		if(A[x][y] == 'R') b++;
		if(A[x][y] == 'L') b--;
		if(A[x][y] == 'U') a--;
		if(A[x][y] == 'D') a++;
		
		if(invalid(a, b)) break;
		x = a, y = b;
	}
	if(f) cout<<x+1<<" "<<y+1;
	else cout<<-1;
}