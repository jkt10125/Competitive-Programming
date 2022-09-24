#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(A[i] > sum + 1) break;
        sum += A[i];
    }
    cout<<sum+1;
}