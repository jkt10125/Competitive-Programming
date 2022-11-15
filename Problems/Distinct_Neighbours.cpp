#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> A;
        for(int i=0; i<2*n; i++) {
            int x;
            cin >> x;
            A[x]++;
        }

        int th = 2 * n - n / 2;

        bool ok = true;
        for(auto [x, y] : A) {
            if(y >= th) {
                ok = false;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}