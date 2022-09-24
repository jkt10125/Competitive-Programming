#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    int best = 0, sum = 0;
    for(int i=0; i<n; i++) {
        sum += A[i];
        sum = max(sum, 0ll);
        best = max(best, sum);
    }
    if(best == 0) cout<<*max_element(A, A+n);
    else cout<<best;
}