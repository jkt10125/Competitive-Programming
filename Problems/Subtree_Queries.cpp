#include <bits/stdc++.h>
using namespace std;

vector<int> val, ans, par;
vector<vector<int>> A;

void dfs(int n) {
    for(int it : A[n]) {
        if(par[it] == -1) {
            par[it] = n;
            dfs(it);
            ans[n] += ans[it];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    val.resize(n+1);
    ans.resize(n+1);
    par.resize(n+1, -1);
    A.resize(n+1);

    for(int i=1; i<=n; i++) cin >> val[i];
    for(int i=2; i<=n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    par[1] = 1;
    dfs(1);

    while(q--) {
        int a;
        cin >> a;
        if(a == 1) {
            int s, x;
            cin >> s >> x;
            ans[s] -= val[s];
            while(par[s] != s) {
                s = par[s];
                
            }
        }
    }
}