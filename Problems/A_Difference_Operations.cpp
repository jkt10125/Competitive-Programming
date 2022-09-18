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

        int hcf = A[0];
        int f = 1;
        for(int i=1; i<n; i++) {
            if(__gcd(A[i], hcf) != hcf) {
                f=0;
                break;
            }
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}