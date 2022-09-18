#include <bits/stdc++.h>
using namespace std;

long long f(vector<long long> &A, int ctr) {
    long long ans = 0;
    for(int i=0; i<32; i++) {
        if(i+ctr == A.size()) break; 
        ans += (A[i+ctr] >> (i+1));
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> A(n);
        for(int i=0; i<n; i++) {
            cin >> A[i];
        }

        vector<long long> psum(n, A[0]);
        for(int i=1; i<n; i++) {
            psum[i] = psum[i-1] + A[i];
        }

        long long ans = 0;
        for(int i=1; i<n; i++) {
            ans = max(ans, psum[i-1] - i * 1ll * k + f(A, i));
        }
        ans = max(ans, f(A, 0));
        ans = max(ans, psum[n-1] - n * 1ll * k);
        cout<<ans<<"\n";
    }
}