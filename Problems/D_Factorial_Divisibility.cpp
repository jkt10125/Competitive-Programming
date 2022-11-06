#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, x;
    cin >> n >> x;
    map<int, int> A;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        A[a]++;
    }

    bool ok = true;
    for(int i=1; i<x; i++) {
        if(A[i] % (i + 1)) {
            ok = false;
            break;
        }
        A[i + 1] += A[i] / (i + 1);
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}