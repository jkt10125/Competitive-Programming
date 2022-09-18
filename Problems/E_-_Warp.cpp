#include <bits/stdc++.h>
using namespace std;

int A, B, C, D, E, F;
int N, M;
set<pair<int, int>> S;

int f(int x, int y, int n) {
	if(S.find({x, y}) != S.end()) return 0;
	if(n == 0) return 1;
	return f(x+A, y+B, n-1) + f(x+C, y+D, n-1) + f(x+E, y+F, n-1);
}

int main() {
	cin >> N >> M;
	cin >> A >> B >> C >> D >> E >> F;
	for(int i=0; i<M; i++) {
		int x, y;
		cin >> x >> y;
		S.insert({x, y});
	}

	cout << f(0, 0, N);

}