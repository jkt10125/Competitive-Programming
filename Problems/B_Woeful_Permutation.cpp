#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n+1] = {0};
        if(n == 1) cout<<1<<endl;
        else {
            if(n & 1) {
                A[1] = 1;
                for(int i=2; i<=n; i+=2) {
                    A[i] = i+1;
                    A[i+1] = i;
                }
            }
            else {
                for(int i=1; i<=n; i+=2) {
                    A[i] = i+1;
                    A[i+1] = i;
                }
            }

            for(int i=1; i<=n; i++) cout<<A[i]<<" ";
            cout<<endl;
        }
    }
}