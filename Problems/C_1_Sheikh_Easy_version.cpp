#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        int l, r;
        cin >> l >> r;
        int psum[n+1] = {0}, pxor[n+1] = {0};
        for(int i=1; i<=n; i++) {
            psum[i] = (psum[i-1] + A[i-1]);
            pxor[i] = (pxor[i-1] ^ A[i-1]);
        }

        int req = psum[r] - psum[l-1] - pxor[r] + pxor[l-1];
        int curr = psum[r] - psum[l-1] - pxor[r] + pxor[l-1];
        cerr << req << endl;
        while(curr == req && r >= l) {
            r--;
            curr = psum[r] - psum[l-1] - pxor[r] + pxor[l-1];
        }
        r++;
        curr = psum[r] - psum[l-1] - pxor[r] + pxor[l-1];
        while(curr == req && r >= l) {
            l++;
            curr = psum[r] - psum[l-1] - pxor[r] + pxor[l-1];
        }
        l--;
        cout << l << " " << r << endl; 
    }
}