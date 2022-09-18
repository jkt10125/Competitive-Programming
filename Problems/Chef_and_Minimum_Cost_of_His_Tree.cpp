#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A, dp;
vector<int> a, l, r, o;
vector<bool> vis;

// dp[n][0] = sum_of_all(min(dp[]))

void dfs(int n) {
    vis[n] = true;
    for(int it : A[n]) {
        if(!vis[it]) {
            dfs(it);

        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        A.assign(n, vector<int>());
        dp.assign(n, vector<int>(2, 0));
        a.assign(n, 0);
        l.assign(n, 0);
        r.assign(n, 0);
        o.assign(n, 0);
        vis.assign(n, false);

        for(int i=0; i<n; i++) cin >> l[i] >> a[i] >> r[i];
        for(int i=1; i<n; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            A[u].push_back(v);
            A[v].push_back(u);
        }

        dfs(0);
    }
}