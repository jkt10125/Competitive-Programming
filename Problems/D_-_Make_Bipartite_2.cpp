#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> colour;
vector<bool> vis;
vector<vector<int>> A;

class DSU {
    public:
    vector<pair<int, int>> parent;
    vector<int> size;
    vector<bool> bipartite;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        bipartite.assign(n, true);
        for(int i=0; i<n; i++) parent[i] = {i, 0};
    }

    pair<int, int> Find(int x) {
        if(x != parent[x].first) {
            int parity = parent[x].second;
            parent[x] = Find(parent[x].first); 
            parent[x].second ^= parity;
        }
        return parent[x];
    }

    void Add_Edge(int x, int y) {
        pair<int, int> X = Find(x), Y = Find(y);
        if(X.first == Y.first) {
            if(X.second == Y.second) {
                bipartite[X.first] = false;
            }
            return;
        }
        if(size[X.first] < size[Y.first]) swap(X, Y);
        parent[Y.first] = {X.first, X.second ^ Y.second ^ 1};
        size[X.first] += size[Y.first];
        bipartite[X.first] = bipartite[X.first] & bipartite[Y.first];
    }

    bool Is_Bipartite(int x) { return bipartite[Find(x).first]; }
};

void dfs(int n) {
    vis[n] = true;
    for (int it : A[n]) {
        if (!vis[it]) {
            colour[it] = 1 - colour[n];
            dfs(it);
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    A.resize(n + 1);
    colour.resize(n + 1);
    vis.resize(n + 1);
    DSU d(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
        d.Add_Edge(u, v);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (!d.Is_Bipartite(i)) {
            ok = false;
            break;
        }
    }

    if (!ok) cout << 0 << endl;
    else {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        int ans = 0;
        map<int, array<int, 2>> M;
        for (int i = 1; i <= n; i++) {
            M[d.Find(i).first][colour[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            ans += M[d.Find(i).first][1 - colour[i]] - A[i].size();
        }
        for (auto it : M) {
            int val = it.second[0] + it.second[1];
            ans += (val * (n - val));
        }
        cout << ans / 2 << endl;
    }
}