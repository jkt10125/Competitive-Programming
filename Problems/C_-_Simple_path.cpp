#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> T;
vector<int> vis, A, B;
int n, x, y;

void dfs(int node) {
	vis[node] = true;
	if(node == y) { B = A; return; }
	A.push_back(node);
	for(int it : T[node]) {
		if(!vis[it]) {
			dfs(it);
		}
	}
	A.pop_back();
}

int main() {
	cin >> n >> x >> y;
	T.resize(n+1);
	vis.resize(n+1);
	for(int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	dfs(x);
	for(auto it : B) cout<<it<<" ";
	cout<<y;
}