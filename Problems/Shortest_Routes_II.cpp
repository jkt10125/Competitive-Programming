#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> W;
const int inf = 1e17;

int n, m, q, u, v, w;

signed main() {
    cin >> n >> m >> q;
    W.assign(n + 1, vector<int> (n + 1, inf));
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        W[u][v] = W[v][u] = min(W[u][v], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (W[i][k] == inf) continue;
            for (int j = 1; j <= n; j++) {
                if (W[k][j] == inf) continue;
                if (W[i][k] + W[k][j] < W[i][j]) {
                    W[i][j] = W[i][k] + W[k][j];
                }
            }
        }
    }

    while (q--) {
        cin >> u >> v;
        if (W[u][v] != inf) cout << W[u][v] << endl;
        else cout << -1 << endl;
    }
}