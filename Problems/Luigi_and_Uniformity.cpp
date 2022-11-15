#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int hcf = 0;
        vector<int> A(n);
        for(int i=0; i<n; i++) {
            cin >> A[i];
            hcf = __gcd(hcf, A[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(A[i] != hcf) ans++;
        }

        cout << ans << endl;

    }
}