#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> A;
        bool ok = true;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            if(A[x]) ok = false;
            A[x] = 1;
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}