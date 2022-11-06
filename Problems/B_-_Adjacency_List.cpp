#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> A(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].insert(v);
        A[v].insert(u);
    }

    for(int i=1; i<=n; i++) {
        cout << A[i].size() << ' ';
        for(int it : A[i]) cout << it << ' ';
        cout << endl;
    }
}