#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k ;
        (((m-k) >= n) ? cout<<"Yes" : cout<<"No") << endl;
    }
}