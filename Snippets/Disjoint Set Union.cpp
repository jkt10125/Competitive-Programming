// CLASSICAL DSU
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

=>> DSU TO SKIP SOME VALUES IN BETWEEN TWO INDEXES
// 0 0 0 0 0 x x x 0 0 0 x 0 x 0 0
// DSU A(n+2);
// for(int i=A.Find(l); i<=r; i=Find(i)) {
//     // This index in the array will never be visited again
//     A.parent[i] = i+1;
// }

=>> DSU TO SUPPORT DISTANCES UPTO THE REPRESENTATIVE
class DSU {
    public:
    vector<pair<int, int>> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for(int i=0; i<n; i++) parent[i] = {i, 0};
    }

    pair<int, int> Find(int x) {
        if(parent[x].first != x) {
            int dist = parent[x].second;
            parent[x] = Find(parent[x].first);
            parent[x].second += dist;
        }
        return parent[x];
    }

    bool Union(int x, int y) {
        int X = Find(x).first, Y = Find(y).first;
        if(X == Y) return false;
        if(size[X] < size[Y]) swap(X, Y);
        parent[Y] = {X, 1};
        size[X] += size[Y];
        return true;
    }
};

=>> DSU TO CHECK BIPARPITENESS ONLINE
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