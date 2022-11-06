#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<int> par, lvl;
int lg;

void dfs(int n) {
    for(int it : A[n]) {
        lvl[it] = lvl[n] + 1;
        dfs(it);
    }
}

void binary_lifting(int n) {
    // A[j][i] : 2^jth parent of i
    lg = log2(n) + 1;
    A.assign(lg, vector<int> (n+1, 0));
    A[0] = par;
    for(int j=1; j<lg; j++) {
        for(int i=1; i<=n; i++) {
            A[j][i] = A[j-1][A[j-1][i]];
        }
    }
}

int kth_ancestor(int n, int k) {
    if(k > lvl[n]) return -1;
    int ctr = 0;
    while(k) {
        if(k & 1) {
            n = A[ctr][n];
        }
        ctr++;
        k >>= 1;
    }
    return n;
}

int lca(int a, int b) {

    if(lvl[a] < lvl[b]) swap(a, b);
    a = kth_ancestor(a, lvl[a] - lvl[b]);
    assert(lvl[a] == lvl[b]);
    for(int i=lg-1; i>=0; i--) {
        if(A[i][a] != A[i][b]) {
            a = A[i][a];
            b = A[i][b];
        }
    }
    return (a == b) ? a : A[0][a];
}

int main() {
    int n, q;
    cin >> n >> q;
    A.resize(n+1);
    lvl.resize(n+1);
    par.resize(n+1);
    for(int i=2; i<=n; i++) {
        cin >> par[i];
        A[par[i]].push_back(i);
    }

    par[1] = 1;
    lvl[1] = 0;
    dfs(1);
    binary_lifting(n);
    while(q--) {
        int m, k;
        cin >> m >> k;
        cout << lca(m, k) << endl;
    }
}