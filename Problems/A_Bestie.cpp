#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i=0; i<n; i++) {
            cin >> A[i];
        }

        int hcf = 0;
        for(int i=0; i<n; i++) hcf = __gcd(hcf, A[i]);

        if(hcf == 1) cout << 0 << endl;
        else {
            hcf = 0;
            for(int i=0; i<n-1; i++) hcf = __gcd(hcf, A[i]);
            hcf = __gcd(hcf, __gcd(A[n-1], n));
            if(hcf == 1) cout << 1 << endl;
            else {    
                hcf = 0;
                for(int i=0; i<n-2; i++) hcf = __gcd(hcf, A[i]);
                hcf = __gcd(hcf, __gcd(A[n-2], n-1));
                hcf = __gcd(hcf, A[n-1]);
                if(hcf == 1) cout << 2 << endl;
                else cout << 3 << endl;
            }
        }
    }
}