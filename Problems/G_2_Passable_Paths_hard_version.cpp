#include <bits/stdc++.h>
using namespace std;

int __a;
int _i() { cin >> __a; return __a; }

int main() {
    int n = _i();
    int p[n+1] = {0}, c[n+1] = {0};
    for(int i=1; i<n; i++) {
        int x = _i(), y = _i();
        if(p[x] == 0) p[x] = y;
        else p[y] = x;
    }
    int q = _i();
    while(q--) {
        int k = _i();
        vector<int> A(k, _i());
        vector<bool> vis(n+1, false);
        sort(A.begin(), A.end());
        int ctr = A.front();
        
        while(p[ctr]) {
            ctr = p[ctr];
            if(find(A.begin(), A.end(), ctr) != A.end()) break;
            if()
            vis[ctr] = true;
        }
    }
    for(int i=0; i<=n; i++) cerr << p[i]<<" ";
}