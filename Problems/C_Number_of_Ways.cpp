#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];
    
    int sum = 0;
    for(int i=0; i<n; i++) sum += A[i];
    if(sum % 3) cout<<"0";
    else {
        sum /= 3;
        int ctr = 0;
        vector<int> B(n, 0), C(n, 0);
        for(int i=0; i<n; i++) {
            ctr += A[i];
            B[i] = (ctr == sum);
        }
        ctr = 0;
        for(int i=n-1; i>=0; i--) {
            ctr += A[i];
            C[i] = (ctr == sum);
        }
        for(int i=1; i<n; i++) {
            // B[i] += B[i-1];
            C[i] += C[i-1];
        }

        int ans = 0;
        for(int i=0; i<n-2; i++) {
            if(B[i]) {
                ans += C[n-1] - C[i+1];
            }
        }
        // for(int i=0; i<n; i++) cerr<<B[i]<<" ";
        // cerr<<endl;
        // for(int i=0; i<n; i++) cerr<<C[i]<<" ";


        cout<<ans;
    }
}