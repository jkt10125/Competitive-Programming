#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> A;

vector<int> dijkstra (int n) {
    set<array<int, 2>> s; // dist[u], u
    vector<int> dist(A.size(), INT_MAX);
    // vector<int> par(A.size(), -1);
    
    // par[n] = n;
    dist[n] = 0;
    
    s.insert({0, n});
    while (!s.empty()) {
        auto [dist_b, b] = *s.begin();
        s.erase(s.begin());
        for (auto [u, w] : A[b]) {
            if (dist[u] > dist_b + w) {
                s.erase({dist[u], u});
                dist[u] = dist_b + w;
                s.insert({dist[u], u});
                // par[u] = b;
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    A.resize(n);
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back({v, w});
        A[v].push_back({u, w});
    }

    for(int i : dijkstra(0)) cout << i << ' ';
}