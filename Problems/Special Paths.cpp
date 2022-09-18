#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n+1);
    for(int i=1; i<=n; i++) cin >> A[i];
    vector<vector<int>> tree(n+1, vector<int>());
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<bool> vis(n+1, false);

    
}