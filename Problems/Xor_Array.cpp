#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int inc = 1, max_inc = 1;
        for(int i=1; i<n; i++) {
            if(A[i] > A[i-1]) inc++;
            else {
                max_inc = max(max_inc, inc);
                inc = 1;
            }
        }
        max_inc = max(max_inc, inc);

        int dec = 1, max_dec = 1;
        for(int i=1; i<n; i++) {
            if(A[i] < A[i-1]) dec++;
            else {
                max_dec = max(max_dec, dec);
                dec = 1;
            }
        }
        max_dec = max(max_dec, dec);
        
        cout << max(max_inc, max_dec) << endl;
    }
}