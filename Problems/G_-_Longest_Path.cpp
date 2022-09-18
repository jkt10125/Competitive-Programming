#include <bits/stdc++.h>
using namespace std;

vector<int> dp; 
vector<bool> vis;
vector<vector<int>> A;

int dfs(int node) {
    if(dp[node] != -1) return dp[node];
    int a = -2;
    for(int it : A[node]) {
        a = max(a, dfs(it));
    }
    return dp[node] = a + 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    A.assign(n+1, vector<int>());
    dp.assign(n+1, -1);
    vector<bool> hsh(n+1, true), hssh(n+1, false);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        hsh[v] = false;
        hssh[u] = false;
    }

    for(int i=1; i<=n; i++) if(hssh[i]) dp[i] = 0;
    
    for(int i=1; i<=n; i++) {
        if(hsh[i]) dfs(i);
    }
    cout<<*max_element(dp.begin(), dp.end()) + 1;
}