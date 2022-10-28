#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), A(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        A[a[i]] = i;
    }

    int ans = 1;
    for(int i=1; i<n; i++) {
        if(A[i] > A[i+1]) ans++;
    }

    while(m--) {
        int i, j;
        cin >> i >> j;

        if(a[i] < n) ans -= (A[a[i]] > A[a[i]+1]);
        if(a[j] < n) ans -= (A[a[j]] > A[a[j]+1]);

        if(a[i] > 1) ans -= (A[a[i]-1] > A[a[i]]);
        if(a[j] > 1) ans -= (A[a[j]-1] > A[a[j]]);

        if(a[i] == a[j] + 1) {
            if(A[a[i]-1] > A[a[i]]) ans++;
        }
        if(a[j] == a[i] + 1) {
            if(A[a[j]-1] > A[a[j]]) ans++;
        }
        swap(a[i], a[j]);
        swap(A[a[i]], A[a[j]]);

        if(a[i] < n) ans += (A[a[i]] > A[a[i]+1]);
        if(a[j] < n) ans += (A[a[j]] > A[a[j]+1]);

        if(a[i] > 1) ans += (A[a[i]-1] > A[a[i]]);
        if(a[j] > 1) ans += (A[a[j]-1] > A[a[j]]);

        if(a[i] == a[j] + 1) {
            if(A[a[i]-1] > A[a[i]]) ans--;
        }
        if(a[j] == a[i] + 1) {
            if(A[a[j]-1] > A[a[j]]) ans--;
        }

        cout << ans << endl;
    }
}