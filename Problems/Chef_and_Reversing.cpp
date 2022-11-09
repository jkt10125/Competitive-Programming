#include <bits/stdc++.h>
using namespace std;

vector<vector<array<int, 2>>> A;

vector<int> bfs(int n) {
    deque<int> s;
    vector<int> dist(A.size(), INT_MAX);
    vector<int> par(A.size(), -1);

    par[n] = n;
    dist[n] = 0;

    s.push_back(n);
    while(!s.empty()) {
        int b = s.front();
        s.pop_front();
        for (auto [u, w] : A[b]) {
            if (dist[u] > dist[b] + w) {
                dist[u] = dist[b] + w;
                if (w) s.push_back(u);
                else s.push_front(u);
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    A.resize(n+1);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back({v, 0});
        A[v].push_back({u, 1});
    }
    int a = bfs(1)[n];

    if (a == INT_MAX) cout << -1;
    else cout << a;    
}