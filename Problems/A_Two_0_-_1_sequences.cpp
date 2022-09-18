#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        string ans = "";
        int pctr = (a[0] != b[0]);
        int ctr = pctr, del_ctr = pctr;
        if(pctr == 0) ans += a[0];
        for(int i=1; i<n; i++) {
            if(a[i] == b[ctr]) {
                
            }
        }
    }
}