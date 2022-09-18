#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<long long> len;

void dfs(int node) {
    for(pair<int, int> it : tree[node]) {
        if(len[it.first] == -1) {
            len[it.first] = len[node] + it.second;
            dfs(it.first);
        }
    }
}

int main() {
    int n;
    cin >> n;
    tree.assign(n+1, vector<pair<int, int>>());
    len.assign(n+1, -1);
    for(int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int q, k;
    cin >> q >> k;
    len[k] = 0;
    dfs(k);
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << len[x] + len[y] << endl;
    }
}