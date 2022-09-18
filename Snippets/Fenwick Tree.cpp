class FenwickTree {
    vector<int> BIT[2];
    int n;
public:
    FenwickTree(int n) {
        this->n = n;
        BIT[0] = BIT[1] = vector<int> (n+1, 0);
    }

    void update(int tree_idx, int idx, int val) {
        // FOR(i, idx, n, (i & -i)) { BIT[tree_idx][i] += val; }
        for(int i=idx; i<=n; i += (i & -i)) { BIT[tree_idx][i] += val; }
    }

    void rangeUpdate(int l, int r, int val) {
        update(0, l, val);
        update(0, r+1, -val);
        update(1, l, val*(l-1));
        update(1, r+1, -val*r);
    }

    int query(int tree_idx, int idx) { // sum of [1 ... idx]
        int sum = 0;
        for(int i=idx; i>0; i -= (i & -i)) { sum += BIT[tree_idx][i]; }
        return sum;
    }

    int prefix_sum(int idx) { return (query(0, idx)*idx - query(1, idx)); }
    int rangeSum(int l, int r) { return prefix_sum(r) - prefix_sum(l-1); }
};

class FenwickTree2D {
    vector<vector<int>> TREE;
public:
    FenwickTree2D(int n, int m) {
        TREE.resize(n+1, vector<int>(m+1, 0));
    }

    void update(int x, int y, int val) {
        for(int i=x; i<TREE.size(); i += (i & -i)) 
            for(int j=y; j<TREE[i].size(); j += (j & -j)) 
                TREE[i][j] += val;

    }

    int query(int x, int y) {
        int sum = 0;
        for(int i=x; i>0; i -= (i & -i))
            for(int j=y; j>0; j -= (j & -j))
                sum += TREE[i][j];
        return sum;
    }

    int query(int x1, int y1, int x2, int y2) {
        return query(x1, y2) - query(x2-1, y2) - query(x1, y1-1) + query(x2-1, y1-1);
    }
};