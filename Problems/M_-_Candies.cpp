#include <iostream>
using namespace std;

const int mod = 1e9+7;

int main() {
    int n, k;
    cin >> n >> k;
    int A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];
    
    long long dp_prev[k+1]={0}, dp_curr[k+1]={0};
    dp_prev[0] = 1;

    for(int i=1; i<=n; i++) {
        dp_curr[0] = 1;

        long long psum[k+1] = {dp_prev[0]};
        for(int j=1; j<=k; j++) {
            psum[j] = psum[j-1] + dp_prev[j];
        }
        for(int j=1; j<=k; j++) {
            if(j > A[i]) dp_curr[j] = psum[j] - psum[j-A[i]-1]; 
            else dp_curr[j] = psum[j];
            dp_curr[j] %= mod;
        }

        for(int j=0; j<=k; j++) dp_prev[j] = dp_curr[j];
    }

    cout<<dp_prev[k];
} 