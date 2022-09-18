#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    int dp[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = 1e9;
        }
    }
    for(int i=0; i<n; i++) dp[i][i] = 0;

    int psum[n] = {A[0]};
    for(int i=1; i<n; i++) psum[i] = psum[i-1] + A[i];

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+psum[j] - ((i) ? psum[i-1] : 0));
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout<<endl;
    }
}