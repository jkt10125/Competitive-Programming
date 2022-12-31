#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int par[n], vis[n] = {0};

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        while (!vis[x] && x) {
            vis[x] = 1;
            x = par[x];
            ans++;
        }
    }

    cout << ans;
}