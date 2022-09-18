#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

vvi A;
vi siz, vis, dp;

void dfs(int node) {
    siz[node] = 1;
    vis[node] = 1;
    for(int i : A[node]) {
        if(!vis[i]) {
            dfs(i);
            siz[node] += siz[i];
        }
    }
}

int calc(int node) {
    if(vis[node]) return dp[node];
    vis[node] = 1;
    if(A[node].size() == 1) {
        dp[node] = 0;
        return dp[node];
    }
    if(A[node].size() == 2) {
        dp[node] = (vis[A[node][0]]) ? siz[A[node][1]] : siz[A[node][0]];
        dp[node]--;
        return dp[node];
    }
    vi tmp;
    for(int i : A[node]) if(!vis[i]) tmp.push_back(i);

    dp[node] = max(siz[tmp[0]]-1+calc(tmp[1]), siz[tmp[1]]-1+calc(tmp[0]));
    return dp[node];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        A.assign(n+1, vi(0));
        siz.assign(n+1, 0);
        vis.assign(n+1, 0);
        dp.assign(n+1, 0);
        for(int i=1; i<n; i++) {
            int x, y;
            cin >> x >> y;
            A[x].push_back(y);
            A[y].push_back(x);
        }
        dfs(1);
        // for(int i=1; i<=n; i++) cerr << siz[i] << " ";
        // cerr<<endl;
        vis.assign(n+1, 0);
        vis[1] = 1;

        for(int i : A[1]) calc(i);
        if(A[1].size() == 1) dp[1] = siz[A[1][0]]-1;
        else dp[1] = max(siz[A[1][0]]-1+dp[A[1][1]], siz[A[1][1]]-1+dp[A[1][0]]);

        // for(int i=1; i<=n; i++) cout << dp[i] << " ";
        cout <<dp[1] << endl;
    }
}