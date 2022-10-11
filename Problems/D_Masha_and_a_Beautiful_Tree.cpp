#include <bits/stdc++.h>
using namespace std;

int f(int A[], int l, int r) {
    if(r == l) return 0;
    int m = (r + l - 1) / 2;
    int ctr = 0;
    ctr += f(A, l, m);
    ctr += f(A, m+1, r);

    if(A[l] > A[m+1]) {
        ctr++;
        for(int i=l; i<=m; i++) {
            swap(A[i], A[i-l+m+1]);
        }
    }
    return ctr;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i=0; i<n; i++) cin >> A[i];

        int ans = f(A, 0, n-1);
        for(int i=0; i<n; i++) {
            if(A[i] != i + 1) ans = -1;
        }

        cout << ans << endl;
    }
}