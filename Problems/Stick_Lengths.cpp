#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];
    sort(A, A+n);
    int ans = A[n/2];
    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += abs(A[i]-ans);
    }
    cout<<sum;
}