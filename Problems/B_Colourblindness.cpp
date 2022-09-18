#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        for(int i=0; i<n; i++) {
            if(a[i] == 'G' || a[i] == 'B') a[i] = '?';
            if(b[i] == 'G' || b[i] == 'B') b[i] = '?';
        }

        if(a == b) cout<<"YES\n";
        else cout<<"NO\n";
    }
}