#include <bits/stdc++.h>
using namespace std;

class dsu {
    public:
    vector<int> par, siz;
    dsu(int n) {
        par.resize(n, 0);
        siz.resize(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int x, int y) {
        int X = find(x);
        int Y = find(y);
        if(X == Y) return false;
        if(Y > X) swap(X, Y);
        par[Y] = X;
        siz[X] += siz[Y];
        return true;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    dsu D(n+1);
    vector<vector<pair<int, int>>> G(n+1);
    vector<pair<int, pair<int, int>>> edges(m);

    for(int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges[i].first = w;
        edges[i].second = {x, y};
    }

    sort(edges.begin(), edges.end());
    for(int i=0; i<m; i++) {
        int u, v;
        make_pair(u, v) = edges[i].second;
        if(D.merge(u, v)) {
            G[u].push_back({v, edges[i].first});
            G[v].push_back({u, edges[i].first});
        }
    }


    
}