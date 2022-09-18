#include <bits/stdc++.h>
using namespace std;
#define int long long
const int lol = 1e18;
vector<vector<pair<int, int>>> A;

void dijkstra(int n, int dest) {
    vector<int> dist(dest+1, lol), parent(dest+1, -1);
    dist[n] = 0, parent[n] = n;
    set<pair<int, int>> S; // {dist[u], u}
    S.insert({0, n});
    while(!S.empty()) {
        int a = S.begin()->second;
        S.erase(S.begin());
        for(auto it : A[a]) {
            if(dist[it.first] > dist[a] + it.second) {
                S.erase({dist[it.first], it.first});
                dist[it.first] = dist[a] + it.second;
                S.insert({dist[it.first], it.first});
                parent[it.first] = a;
            }
        }
    }
    if(dist[dest] == lol) cout<<-1;
    else {
        vector<int> AA;
        int ctr = dest;
        while(parent[ctr] != ctr) {
            AA.push_back(ctr);
            ctr = parent[ctr];
        }
        AA.push_back(1);
        reverse(AA.begin(), AA.end());
        for(int i : AA) cout<<i<<" ";
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    A.resize(n+1);
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back({v, w});
        A[v].push_back({u, w});
    }
    dijkstra(1, n);
}