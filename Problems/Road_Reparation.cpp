#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int Kruskal(int n, vector<pair<int, pair<int, int>>> &edges) {
    sort(edges.begin(), edges.end());
    DSU D(n + 1); // Be careful about the 1 based indexing
    int ans = 0;
    int ctr = 0;
    for(auto it : edges) {
        if(D.Union(it.second.second, it.second.first)) {
            ans += it.first;
            ctr++;
        }
    }
    if(ctr == n - 1) return ans;
    else return -1;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges(m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    int a = Kruskal(n, edges);
    if (a != -1) cout << a << endl;
    else cout << "IMPOSSIBLE\n";

}