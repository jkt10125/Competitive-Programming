#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    int a = log2(n);
    a = 1 << a;
    return (a << 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            cout << i << ' ' << f(x) - x << endl;
        }
    }
}