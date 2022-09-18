#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<int> dp, good;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;
    for(int it : A[node]) {
        if(!vis[it]) {
            dp[it] = dp[node] + good[it];
            dfs(it);
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    good.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> good[i];
    A.assign(n+1, vector<int>());
    dp.assign(n+1, 0);
    vis.assign(n+1, false);

    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    dp[1] = good[1];
    dfs(1);
    for(int i=0; i<=n; i++) cerr << dp[i]<<" ";
    int ans = 0;
    for(int i=2; i<=n; i++) {
        if(A[i].size() == 1) {
            if(dp[i] <= c) ans++;
        }
    }
    cout<<ans;
}