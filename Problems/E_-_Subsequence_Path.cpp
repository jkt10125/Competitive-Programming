#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    int u[m+1], v[m+1], w[m+1];
    for(int i=1; i<=m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
    int A[k+1];
    for(int i=1; i<=k; i++) {
        cin >> A[i];
    }


    vector<int> dist(n+1, 1e16);
    dist[1] = 0;
    for(int i=1; i<=k; i++) {
        if(dist[u[A[i]]] == INT_MAX) continue;
        dist[v[A[i]]] = min(dist[v[A[i]]], dist[u[A[i]]] + w[A[i]]);
    }

    if(dist[n] == 1e16) cout<<-1;
    else cout<<dist[n];
}