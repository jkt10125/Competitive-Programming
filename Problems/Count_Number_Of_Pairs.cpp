#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n+1);
        for(int i=1; i<=n; i++) cin >> A[i];
        const int inv = 2*n;
        vector<int> arr(4*n+2);
        int ans = 0;
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=min(n, 2*n/k); i++) {
                int a = A[i] - k*i;
                arr[a+inv]++;
                ans += arr[inv-a];
            }
            for(int i=1; i<=min(n, 2*n/k); i++) {
                int a = A[i] - k*i;
                arr[a+inv] = 0;
            }
        }
        cout << ans << endl;
    }
}