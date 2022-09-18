#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    long long dp[n];
    dp[0] = 0;
    dp[1] = abs(A[0]-A[1]);
    for(int i=2; i<n; i++) dp[i] = min(dp[i-1]+abs(A[i]-A[i-1]), dp[i-2]+abs(A[i]-A[i-2]));
    cout<<dp[n-1];
}