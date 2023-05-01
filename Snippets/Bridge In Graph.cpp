#include <bits/stdc++.h>

const int N = 100000;

std::vector<int> A[N];
std::set<std::pair<int, int>> bridges;
int tin[N], low[N];
bool vis[N];
int timer;

void dfs(int x, int p) {
    vis[x] = true;
    tin[x] = low[x] = timer++;
    for (int y : A[x]) {
        if (y != p) {
            if (vis[y]) {
                low[x] = std::min(low[x], tin[y]);
            }
            else {
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
                if (low[y] > tin[x]) {
                    bridges.insert({x, y});
                }
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        A[i].clear();
        tin[i] = low[i] = INT_MAX;
        vis[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            timer = 0;
            dfs(i, -1);
        }
    }

    for (auto it : bridges) {
        std::cout << it.first << ' ' << it.second << std::endl;
    }

    return 0;
}
