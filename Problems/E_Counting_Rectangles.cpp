#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        vector<vector<int>> dp(N, vector<int> (N, 0));
        int n, q;
        cin >> n >> q;
        for(int i=0; i<n; i++) {
            int h, w;
            cin >> h >> w;
            dp[h][w]++;
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                dp[i][j] = i * j * dp[i][j];
            }
        }

        for(int i=1; i<N; i++) {
            for(int j=1; j<N; j++) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }

        // for(int i=1; i<11; i++) {
        //     for(int j=1; j<11; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        while(q--) {
            int h, w, H, W;
            cin >> h >> w >> H >> W;
            cout << dp[H-1][W-1] - dp[H-1][w] - dp[h][W-1] + dp[h][w] << endl;
        }
    }
}