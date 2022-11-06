#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<int> vis, siz, dis, ans, lvl;

void dfs(int n) {
    vis[n] = true;
    dis[n] = 0;
    siz[n] = 0;
    for(int it : A[n]) {
        if(!vis[it]) {
            dfs(it);
            siz[n] += siz[it];
            dis[n] += dis[it] + siz[it] + 1;
        }
    }
}

void dfs2(int n) {
    vis[n] = true;
    int sum = 0;
    for(int it : A[n]) sum += dis[it];
}

int main() {
    int n;
    cin >> n;
    vis.resize(n+1);
    siz.resize(n+1);
    dis.resize(n+1);
    ans.resize(n+1);
    A.resize(n+1);

    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    dfs(1);
    ans[1] = accumulate(dis.begin(), dis.end(), 0ll);

    vis.assign(n+1, false);
    dfs2(1);

}