#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
vector<int> A;

bool ok(int sum) {
    int apartment = 1, s = 0;
    for(int i=0; i<n; i++) {
        if(A[i] > sum) return false;
        if(s + A[i] > sum) {
            apartment++;
            s = A[i];
        }
        else s += A[i];
    }
    return (apartment <= k);
}

signed main() {
    cin >> n >> k;
    A.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];

    int optimal_sum = -1;
    int l = 0, r = 2e15;

    while(l <= r) {
        int m = (l + r) / 2;
        if(ok(m)) {
            optimal_sum = m;
            r = m-1;
        }
        else {
            l = m+1;
        }
    }

    cout<<optimal_sum;
}