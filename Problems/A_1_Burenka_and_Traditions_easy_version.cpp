#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // dp[i][j] : min time required to make A[0 ... i-1] = 0 s.t A[i] = j
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<vector<int>> dp(5001, vector<int> (5001, 0));
        
    }
}