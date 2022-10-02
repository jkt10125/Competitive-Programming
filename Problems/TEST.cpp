#include <bits/stdc++.h>
using namespace std;

map<int, int> pi;

int main() {
    int m, k;
    cin >> m >> k;
    int ctr = 1;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        if(!pi[u]) pi[u] = ctr++;
        if(!pi[v]) pi[v] = ctr++;
        
    }
}