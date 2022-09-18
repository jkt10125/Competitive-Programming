#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool A[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    // dp[i] : number of pairs of any i men with first i women
    // dp[i] = dp[i-1]
    
    int dp[n+1];
    for(int i=0; i<n; i++) dp[1] += A[0][i];
    for(int i=1; i<n; i++) {
        for(int j=0; j<(1<<n); j++) {

        }
    }
}