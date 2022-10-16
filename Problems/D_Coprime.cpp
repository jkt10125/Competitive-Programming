#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(1004, 0);
        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            A[x] = i;
        }
        int ans = -1;
        for(int i=1; i<=1000; i++) {
            if(!A[i]) continue;
            for(int j=1; j<=1000; j++) {
                if(!A[j]) continue;
                if(__gcd(i, j) == 1) {
                    ans = max(ans, A[i] + A[j]);
                }
            }
        }
        cout<<ans<<endl;
    }
}