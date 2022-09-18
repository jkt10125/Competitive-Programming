#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int Find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }
    bool Union(int x, int y) {
        int X = Find(x), Y = Find(y);
        if(X == Y) return false;
        if(size[X] < size[Y]) swap(X, Y);
        parent[Y] = X, size[X] += size[Y];
        return true;
    }
    int Size(int x) { return size[Find(x)]; }
};

// edges = {w, {u, v}} : in sorted manner
vector<vector<pair<int, int>>> Kruskal(int n, vector<pair<int, pair<int, int>>> &edges) {
    sort(edges.begin(), edges.end());
    DSU D(n); // Be careful about the 1 based indexing
    vector<vector<pair<int, int>>> A;
    for(auto it : edges) {
        int u, v, w;
        make_pair(w, make_pair(u, v)) = it;
        if(D.Union(u, v)) {
            A[u].push_back({v, w});
            A[v].push_back({u, w});
        }
    }
    return A;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges(m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    vector<vector<pair<int, int>>> A = Kruskal(n, edges);
}