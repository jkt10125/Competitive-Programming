#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> A(2*n);
        for(int i=0; i<2*n; i++) cin >> A[i];

        sort(A.begin(), A.end());
        int f = 1;
        for(int i=0; i<n; i++) {
            if(A[i+n] - A[i] < x) f = 0;
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}