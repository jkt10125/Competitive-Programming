#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e16;
vector<vector<array<int, 2>>> A;
int n, m, u, v, w;

void dijkstra () {
    vector<int> dist(n + 1, inf);
    set<array<int, 2>> s; // dist[u], u
    s.insert({0, 1});
    dist[1] = 0;
    while (!s.empty()) {
        int u = (*s.begin())[1];
        s.erase(s.begin());
        for (auto [v, w] : A[u]) {
            if (dist[u] + w < dist[v]) {
                s.erase({dist[v], v});
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}

signed main() {
    cin >> n >> m;
    A.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        A[u].push_back({v, w});
    }

    dijkstra();    
}