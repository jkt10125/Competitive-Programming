#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int mn, mx;
        mn = mx = a[0];
        int flag = 1;
        for(int i=0; i<n; i++) {
            if(a[i] > mn && a[i] < mx) {
                flag = 0;
                break;
            }
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        if(flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}