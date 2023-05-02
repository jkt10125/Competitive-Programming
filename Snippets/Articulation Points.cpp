#include <bits/stdc++.h>

const int N = 100000;

std::vector<int> A[N], articulation_points;
int tin[N], low[N];
bool vis[N];
int timer;

void dfs(int x, int p) {
    int child  = 0;
    vis[x] = true;
    tin[x] = low[x] = timer++;
    for (int y : A[x]) {
        if (y != p) {
            if (!vis[y]) {
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
                if (low[y] >= tin[x] && p != 1) {
                    articulation_points.push_back(x);
                }
                child++;
            }
            else {
                low[x] = std::min(low[x], tin[y]);
            }
        }
    }

    if (p == -1 && child > 1) {
        articulation_points.push_back(x);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        A[i].clear();
        tin[N] = low[N] = INT_MAX;
        vis[N] = false;
    }

    for (int i = 0; i < n; i++) {
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

    for (auto it : articulation_points) {
        std::cout << it << ' ';
    }
}