#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        int A[r+1];
        for(int i=l; i<=r; i++) cin >> A[i];
        
        int ans = 0;
        for(int i=17; i>=0; i--) {
            for(int j=l; j<=r; j++) {
                if((A[j] ^ ans) > r) {
                    if(A[j] & (1 << i)) {
                        ans |= (1 << i);
                    }
                }
            } 
        }

        cout << ans << endl;
    }
}