#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    vector<int> M(n);
    int sum = 0, ans = 0;

    for(int i=0; i<n; i++) {
        sum += A[i];
        M[(sum % n + n) % n]++;
    }

    for(int i=1; i<n; i++) ans += (M[i] * (M[i] - 1)) / 2;
    ans += M[0] * (M[0] + 1) / 2;

    cout << ans;
}