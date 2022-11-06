#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
        }
        n = 10 - n;

        cout << n * (n - 1) * 3 << endl;
    }
}