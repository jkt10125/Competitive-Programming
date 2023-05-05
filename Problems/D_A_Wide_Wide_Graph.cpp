#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;

vector<int> d;

void dfs(int x, int par) {
    for (int it : A[x]) {
        if(it != par) {
            d[it] = d[x] + 1;
            dfs(it, x);
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    A.resize(n);
    d.resize(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    d[0] = 0;
    dfs(0, -1);

    int a = max_element(d.begin(), d.end()) - d.begin();
    d[a] = 0;
    dfs(a, -1);
    vector<int> dist_a = d;

    int b = max_element(d.begin(), d.end()) - d.begin();
    d[b] = 0;
    dfs(b, -1);
    vector<int> dist_b = d;

    for (int i = 0; i < n; ++i) {
        d[i] = max(dist_a[i], dist_b[i]);
    }

    sort(d.begin(), d.end());
    vector<int> ans(n, 1);
    int ctr = 0;

    for (int i = 0; i < n; i++) {
        while (d[ctr] < i + 1 && ctr < n - 1) ctr++;
        ans[i] = ctr + 1; 
    }

    for (int i : ans) cout << i << ' ';
    cout << endl; 
}