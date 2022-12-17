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

int main() {
    int n, m;
    cin >> n >> m;
    DSU d(n + 1);
    int max_size = 1;
    int count = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (d.Union(u, v)) {
            count--;
            max_size = max(max_size, d.Size(u));
        }
        cout << count << ' ' << max_size << endl;
    }
}