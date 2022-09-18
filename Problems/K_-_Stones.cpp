#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];
    
    int dp[k+1] = {0};
    // dp[i] : who will win if K = i
    for(int j=1; j<=k; j++) {
        int f = 0;
        for(int i=1; i<=n; i++) {
            if(j < A[i]) break;
            if(dp[j-A[i]] == 0) f = 1;
        }
        dp[j] = f;
    }

    if(dp[k]) cout<<"First";
    else cout<<"Second";
}