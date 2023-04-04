#include <bits/stdc++.h>
using namespace std;

vector<int> lvl;

void dfs(int u, int p, vector<vector<int>> &adj) {
    for (int v : adj[u]) {
        if (v != p) {
            lvl[v] = lvl[u] + 1;
            dfs(v, u, adj);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    lvl.resize(n + 1);

    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            root = i;
            break;
        }
    }
    lvl[root] = 0;

    dfs(root, -1, adj);

    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        A[lvl[i]]++;
    }
    A[0] = 0;

    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }

    int mx = *max_element(lvl.begin(), lvl.end());

    for (int i = 1; i <= n; i++) {
        int ans = max(1, 2 * i - mx);
        ans = min(ans, n);
        std::cout << ans << ' ';
    }

}