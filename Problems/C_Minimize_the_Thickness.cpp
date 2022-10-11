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

        vector<int> sum(n, A[0]);
        for(int i=1; i<n; i++) sum[i] = A[i] + sum[i-1];

        int ans = n;
        for(int i=0; i<n; i++) {
            int len = i+1;
            int k = i;
            bool ok = true;
            for(int j=i+1; j<n; j++) {
                if(sum[j] == sum[i] + sum[k]) {
                    len = max(len, j-k);
                    k = j;
                }
                else if(sum[j] > sum[i] + sum[k]) {
                    ok = false;
                    break;
                }
            }
            if(k != n-1) {
                if(sum[n-1] != sum[i] + sum[k]) {
                    ok = false;
                }
                else len = max(len, n-1-k);
            }

            if(ok) ans = min(ans, len);
        }

        cout<<ans<<endl;
    }
}