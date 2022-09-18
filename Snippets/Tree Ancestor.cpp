// zero based indexing in the 2d lift array
class TreeAncestor {
    vector<vector<int>> lift;
    vector<int> lvl;
    int n, log;
    public:
    TreeAncestor(vector<vector<int>> &tree, int root) {
        n = tree.size();
        log = log2(n);
        lift.assign(log+1, vector<int> (n, 0));
        lvl.resize(n, -1);

        lvl[root] = 0;
        lift[0][root] = root;
        dfs(tree, root);

        for(int i=1; i<=log; i++) {
            for(int j=0; j<n; j++) {
                lift[i][j] = lift[i-1][lift[i-1][j]];
            }
        }
    }

    void dfs(vector<vector<int>> &tree, int node) {
        for(int it : tree[node]) {
            if(lvl[it] == -1) {
                lvl[it] = lvl[node] + 1;
                lift[0][it] = node;
                dfs(tree, it);
            }
        }
    }

    int getKthAncestor(int node, int k) {
        if(k > lvl[node]) return -1;
        int ctr = 0;
        while(k) {
            if(k & 1) node = lift[ctr][node];
            k >>= 1;
            ctr++;
        }
        return node;
    }

    int LCA(int x, int y) {
        if(lvl[y] > lvl[x]) swap(x, y);
        int lvl_difference = lvl[x] - lvl[y];
        x = getKthAncestor(x, lvl_difference);
                
        for(int i=log; i>=0; i--) {
            if(lift[i][x] != lift[i][y]) {
                x = lift[i][x];
                y = lift[i][y];
            }
        }
        return (x == y) ? x : lift[0][x];
    }
};