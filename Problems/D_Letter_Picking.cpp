#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i=0; i<n-1; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
        }

        for(int j=0; j<n; j++) {
            for(int i=n-1; i>=0; i--) {
                if(i > j-2) continue;
                if((j-i+1) & 1) continue;
                int a = 1;
                a = a & dp[i+1][j-1];
                a = a & dp[i+2][j];
                a = a & dp[i][j-2];
                dp[i][j] = a;
            }
        }

        if(dp[0][n-1]) cout<<"Draw";
        else cout<<"Alice";
        cout<<endl;
    }
}