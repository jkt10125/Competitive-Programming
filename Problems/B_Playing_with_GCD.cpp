#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        bool ok = true;
        for(int i=1; i<n-1; i++) {
            int a = __gcd(A[i-1], A[i+1]);
            if(A[i] % a != 0) ok = false;
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}