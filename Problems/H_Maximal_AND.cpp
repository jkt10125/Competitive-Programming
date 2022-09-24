#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(31);
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            for(int i=0; i<31; i++) {
                if(x & (1 << i)) A[i]++;
            }
        }

        int ans = 0;
        for(int i=30; i>=0; i--) {
            int res = n - A[i];
            if(res <= k) ans += (1 << i), k -= res;
        }

        cout<<ans<<endl;
    }
}