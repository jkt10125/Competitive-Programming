#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n+1, (1 << 30) - 1);
    vector<vector<pair<int, int>>> G(n+1);
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u] = A[u] & w;
        A[v] = A[v] & w;

        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    for(int i=1; i<=n; i++) {
        int t = 0;
        for(auto p : G[i]) {
            t = t | (p.second & ~A[p.first]);
            if(p.first == i) { t = p.second; break; }
        }
        A[i] = t;
    }

    for(int i=1; i<=n; i++) cout<<A[i]<<" ";
}