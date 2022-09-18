#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        int A[n];
        for(int i=0; i<n; i++) cin >> A[i];

        vector<bool> ans(n, false);
        for(int i=0; i<n; i++) {
            if(A[i] <= q) ans[i] = true;
        }

        int Q = 0;
        for(int i=n-1; i>=0; i--) {
            if(Q >= q) break;
            if(A[i] > Q) ans[i] = true, Q++;
        }
        for(int i=0; i<n; i++) cout<<ans[i];
        cout<<endl;
    }
}