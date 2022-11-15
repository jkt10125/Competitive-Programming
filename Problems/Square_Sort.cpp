#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<int> S = A, R = A;
        vector<int> r(n), s(n);

        for(int i=1; i<n; i++) {
            int ctr = r[i-1];
            if(R[i-1] > R[i]) {
                for(int j=i-1; j>=0; j--) {
                    if(R[j] > R[j+1]) {while(R[j] > R[j+1]) {
                        R[j] = sqrt(R[j]);
                        ctr++;
                    }}
                    else break;
                }
            }
            r[i] = ctr;
        }

        for(int i=n-2; i>=0; i--) {
            int ctr = s[i+1];
            if(S[i+1] < S[i]) {
                for(int j=i+1; j<n; j++) {
                    if(S[j] < S[j-1]) {while(S[j] < S[j-1]) {
                        if(S[j] > 1e9 || S[j] == 1) {
                            ctr = INT_MAX;
                            break;
                        }
                        S[j] = S[j] * S[j];
                        ctr++;
                    }}
                    else break;
                }
            }
            s[i] = ctr;
        }
        
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            ans = min(ans, r[i] + s[i]);
        }
        cout << ans << endl;
    }
}