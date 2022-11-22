#include <bits/stdc++.h>
using namespace std;

#define pii array<int, 2>

int main() {
    int n, x;
    cin >> n >> x;
    int A[n];
    map<int, pii> m;
    for(int i=0; i<n; i++) cin >> A[i];

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            m[A[i]+A[j]] = {i, j};
        }
    }

    bool ok = false;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(!m[x-A[i]-A[j]].empty()) {
                pii a = m[x-A[i]-A[j]];
                if(a[0] > j) {
                    cout << i+1 << ' ' << j+1 << ' ' << a[0]+1 << ' ' << a[1]+1 << endl;
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }

    if(!ok) cout << "IMPOSSIBLE";
}