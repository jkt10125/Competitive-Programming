#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, q;
    cin >> n >> q;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    int sum = n * (n + 1) / 2;
    for(int i=1; i<n; i++) {
        sum += (A[i] != A[i-1]) * i * (n - i);
    }
    while(q--) {
        int i, x;
        cin >> i >> x;
        i--;
        if(i > 0) {
            sum -= (A[i] != A[i-1]) * i * (n - i);
        }
        if(i < n-1) {
            sum -= (A[i] != A[i+1]) * (i + 1) * (n - i - 1);
        }
        A[i] = x;
        if(i > 0) {
            sum += (A[i] != A[i-1]) * i * (n - i);
        }
        if(i < n-1) {
            sum += (A[i] != A[i+1]) * (i + 1) * (n - i - 1);
        }

        cout<<sum<<endl;
    }
    return 0;
}