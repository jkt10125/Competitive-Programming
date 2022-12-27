/*
** Date: 26/12/2022 | Time: 22:14:01
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

vector<bool> col, vis;
vector<vector<int>> A;


void dfs(int n) {
    vis[n] = true;
    for (int it : A[n]) {
        if (!vis[it]) {
            dfs(it);
            if (!col[n] && !col[it]) {
                col[n] = col[it] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vis.resize(n + 1);
    col.resize(n + 1);
    A.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    dfs(1);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += col[i + 1];
    }
    assert(sum % 2 == 0);
    cout << sum / 2 << endl;
}