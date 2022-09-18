#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<int> dp[2];
vector<bool> vis;

void dfs(int n) {
    vis[n] = true;
    for(int it : A[n]) {
        if(!vis[it]) {
            dfs(it);
            dp[0][n] *= dp[0][it] + dp[1][it];
            dp[1][n] *= dp[0][it];
            // cout << "line : " << __LINE__ << ", n = " << n << '\n';
        }
    }
}

int main() {
    int n;
    cin >> n;

    A.resize(n+1);
    dp[0].resize(n+1, 1);
    dp[1].resize(n+1, 1);
    vis.assign(n+1, 0);

    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    dfs(1);

    cout<<dp[0][1]+dp[1][1]<<endl;
    // for(int i=0; i<=n; i++) cout<<dp[0][i]<<" ";
    // cout<<endl;
    // for(int i=0; i<=n; i++) cout<<dp[1][i]<<" ";
}