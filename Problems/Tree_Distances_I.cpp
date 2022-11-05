#include <bits/stdc++.h>
using namespace std;

vector<int> lvl, vis;
vector<vector<int>> A;

void dfs(int n) {
    vis[n] = true;
    for(int i : A[n]) {
        if(!vis[i]) {
            lvl[i] = lvl[n] + 1;
            dfs(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    lvl.resize(n+1);
    vis.resize(n+1);
    A.resize(n+1);

    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    lvl[1] = 0;
    dfs(1);

    int p1 = max_element(lvl.begin(), lvl.end()) - lvl.begin();
    lvl.assign(n+1, 0);
    vis.assign(n+1, 0);

    lvl[p1] = 0;
    dfs(p1);

    vector<int> m1 = lvl;
    int p2 = max_element(lvl.begin(), lvl.end()) - lvl.begin();
    lvl.assign(n+1, 0);
    vis.assign(n+1, 0);

    lvl[p2] = 0;
    dfs(p2);
    
    for(int i=1; i<=n; i++) cout << max(m1[i], lvl[i]) << " ";
    
}