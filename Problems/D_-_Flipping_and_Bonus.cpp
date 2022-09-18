#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];
    int bonus[n+1] = {0};
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        bonus[a] = b;
    }

    long long dp_prev[n+1], dp_curr[n+1];
    
    for(int i=1; i<=n; i++) dp_prev[i] = -1e9;
    dp_prev[0] = 0;
    for(int i=1; i<=n; i++) {
        dp_curr[0] = dp_prev[0];
        for(int j=1; j<=n; j++) {
            dp_curr[0] = max(dp_curr[0], dp_prev[j]);
        }

        for(int j=1; j<=i; j++) {
            dp_curr[j] = dp_prev[j-1] + A[i] + bonus[j];
        }
        for(int j=i+1; j<=n; j++) dp_curr[j] = -1e9;
        for(int i=0; i<=n; i++) dp_prev[i] = dp_curr[i];
    }
    long long ans = dp_prev[0];
    for(int i=1; i<=n; i++) ans = max(ans, dp_prev[i]);

    cout<<ans;
}