#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> A, B;

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
    int n, m, k;
    cin >> n >> m >> k;
    A.resize(n + 1);
    B.resize(n + 1);
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        B[u].push_back({v, w});
        B[v].push_back({u, w});
    }

    vector<int> aa(n + 1);
    for (int i = 0; i<k; i++) {
        int x;
        cin >> x;
        aa[x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (aa[i] == 1) {
            for (auto [it, ww] : B[i]) {
                A[i].push_back({it, 1});
                A[it].push_back({i, 1});
            }
        }
        else {
            for (auto [it, ww] : B[i]) {
                if (ww) {
                    A[i].push_back({it, 1});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto [it, ww] : B[i]) {
            cerr << i << ' ';
        }
        cerr << endl;
    }

    for(int i : dijkstra(1)) cout << i << ' ';
}