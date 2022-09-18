#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> parent(n+1);
    for(int i=2; i<=n; i++) {
        cin >> parent[i];
    }

    int ctr = 0;
    int node = n;
    while(node != 1) {
        node = parent[node];
        ctr++;
    }
    cout<<ctr;
}