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

        int ctr = -1;
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(A[i] == 1) {ctr = i; break;}
        }

        for(int i=ctr; i>0; i--) {
            swap(A[i], A[i-1]);
            ans++;
        }
        for(int i=0; i<n; i++) {
            if(A[i] == n) {
                ctr = i; break;
            }
        }
        for(int i=ctr; i<n-1; i++) {
            swap(A[i], A[i+1]);
            ans++;
        }

        cout<<ans<<endl;
    }
}