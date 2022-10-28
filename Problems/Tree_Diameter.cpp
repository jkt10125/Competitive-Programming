#include <bits/stdc++.h>
using namespace std;

vector<int> lvl;
vector<vector<int>> A;

void dfs(int n) {
    for(int it : A[n]) {
        if(lvl[it] == -1) {
            lvl[it] = lvl[n] + 1;
            dfs(it);
        }
    }
}

int main() {
    int n;
    cin >> n;
    A.resize(n+1);
    lvl.assign(n+1, -1);
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    lvl[1] = 0;
    dfs(1);
    int node = max_element(lvl.begin(), lvl.end()) - lvl.begin();
    lvl.assign(n+1, -1);
    lvl[node] = 0;
    dfs(node);
    cout << *max_element(lvl.begin(), lvl.end());
}