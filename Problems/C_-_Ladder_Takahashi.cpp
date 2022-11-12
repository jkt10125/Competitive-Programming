#include <bits/stdc++.h>
using namespace std;

map<int, int> vis;
int ans;

map<int, vector<int>> A;

void dfs (int x) {
    vis[x] = 1;
    ans = max(ans, x);
    for (int it : A[x]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
}

int main() {
    int n;
    cin >> n;
    ans = 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    dfs(1);

    cout << ans;
}