#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> T;

int main() {
    int n, k;
    T.resize(n+1);
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    
}