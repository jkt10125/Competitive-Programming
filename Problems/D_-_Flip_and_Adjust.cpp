#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int A[n], B[n];
    for(int i=0; i<n; i++) cin >> A[i] >> B[i];

    vector<vector<int>> dp(n, vector<int> (s+1));
    // dp[i][j] : whether you can make sum j using first i indexes
    // where you must take the ith 

    for(int i=0; i<n; i++) dp[i][0] = 0;
    dp[0][A[0]] = 1;
    dp[0][B[0]] = 1;
    for(int j=1; j<=s; j++) {
        for(int i=1; i<n; i++) {
            if(j < A[i]) {
                if(j < B[i]) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j-B[i]];
            }
            else {
                if(j < B[i]) dp[i][j] = dp[i-1][j-A[i]];
                else dp[i][j] = max(dp[i-1][j-A[i]], dp[i-1][j-B[i]]);
            }
        }
    }

    if(dp[n-1][s]) {
        cout<<"Yes\n";
        // vector<int> aa;
        // for(int i=n-1; i>0; i--) {
        //     if(dp[i][s] == dp[i-1][s-A[i]]) {
        //         aa.push_back(0);
        //         s -= A[i];
        //     }
        //     else {
        //         aa.push_back(1);
        //         s -= B[i];
        //     }
        // }
        // if(s == A[0]) aa.push_back(0);
        // else aa.push_back(1);
        // reverse(aa.begin(), aa.end());
        // for(auto it : aa) {
        //     if(it) cout<<'T';
        //     else cout<<'H';
        // }
    }
    else cout<<"No";
}